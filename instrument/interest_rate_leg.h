// interest_rate_leg.h - fixed and floating legs of an interest rate swap
#pragma once
#include "../datetime/datetime.h"
#include "instrument.h"

namespace fms {
namespace fixed_income {

	// value type instrument using datetime::date
	template<class T = double, class C = double>
	class leg : public vector::instrument<T,C,fms::datetime::date> {
	public:
		// indicative data
		int count_; fms::datetime::time_unit unit_; // e.g., 10, UNIT_YEARS
		fms::datetime::payment_frequency freq_;
		fms::datetime::day_count_basis dcb_;
		fms::datetime::roll_convention roll_;
		fms::datetime::holiday_calendar cal_;
		// typical swap conventions
		leg(
			int count = 3, fms::datetime::time_unit unit = fms::datetime::UNIT_MONTHS,
			fms::datetime::payment_frequency freq = FREQ_SEMIANNUALLY,
			fms::datetime::day_count_basis dcb = DCB_30U_360,
			fms::datetime::roll_convention roll = ROLL_MODIFIED_FOLLOWING,
			fms::datetime::holiday_calendar cal = CALENDAR_NONE)
		: 
		  count_(count), unit_(unit), freq_(freq),
		  dcb_(dcb), roll_(roll), cal_(cal),
		{
			ensure (0 < freq_ && freq_ <= FREQ_MONTHLY);
		}
		virtual ~leg()
		{ }

	};
	//!!!bolenpeng move to interest_rate_leg_fixed.h
	// fixed payments
	namespace fixed {
		template<class T = double, class C = double>
		class leg_fixed: public fixed_income::leg<T,C> {
			public:
				leg_fixed() //!!! use base constructor!!!
				{ }
				~leg_fixed()
				{ }

				// create cash flows given settlement date and fixed coupon
				const leg_fixed<T,C>& fix(const date& set, const date& eff, const C& coupon)
				{
					date mat(eff);
					mat.incr(count_, unit_);
					mat.adjust(roll_, cal_);

					date d0(eff);
					for (int i = 1; d0 <= mat; ++i) {
						date d1(eff);
						d1.incr(12*i/freq_, fms::datetime::UNIT_MONTHS).adjust(roll_, cal_);
						add(d1, coupon*d1.diff_dcb(d0, dcb_));
						d0 = d1;
					}

					return *this;
				}
			};
	} // fixed
	namespace floating {
		//!!!cxccxlcxc move to interest_rate_leg_float.h
		template<class T = double, class C = double>
		class leg_float : public vector::instrument<T,C,fms::datetime::date> {
		public:
			// indicative data
			int count_; fms::datetime::time_unit unit_; // e.g., 10, UNIT_YEARS
			fms::datetime::payment_frequency freq_;
			fms::datetime::day_count_basis dcb_;
			fms::datetime::roll_convention roll_;
			fms::datetime::holiday_calendar cal_;
			// typical swap conventions
			leg_float(
				int count = 3, fms::datetime::time_unit unit = fms::datetime::UNIT_MONTHS,
				fms::datetime::payment_frequency freq = FREQ_SEMIANNUALLY,
				fms::datetime::day_count_basis dcb = DCB_30U_360,
				fms::datetime::roll_convention roll = ROLL_MODIFIED_FOLLOWING,
				fms::datetime::holiday_calendar cal = CALENDAR_NONE)
			: 
			  count_(count), unit_(unit), freq_(freq),
			  dcb_(dcb), roll_(roll), cal_(cal),
			{
				ensure (0 < freq_ && freq_ <= FREQ_MONTHLY);
			}
			virtual ~leg_float()
			{ }

			// create cash flows given settlement date and fixed coupon
			const leg_float<T,C>& fix(const fms::datetime::date& val, double coupon)
			{
				fms::datetime::date eff_{effective());

				ensure (eff_);

				date mat(eff_);
				mat.incr(count_, unit_);
				mat.adjust(roll_, cal_);

				// long the floating leg
				fix(eff_, 1);
				// short the fixed leg
				fix(mat, -1);

				return *this;
			}
		};
	} // float

} // namespace instrument
} // namespace fms

#ifdef _DEBUG

using namespace fms::fixed_income;

void test_fixed_income_interest_rate_leg()
{
	using namespace fms::fixed;
	
	leg_fixed<> irlf1;

	irlf1.fix(date(2014, 10, 22), date(2015, 10, 22), 0.02);

	date mat(date(2015, 10, 22));
	
	mat.incr(3, fms::datetime::UNIT_MONTHS);
	mat.adjust(ROLL_MODIFIED_FOLLOWING, CALENDAR_NONE);

	date d0(date(2015, 10, 22));
	for (int i = 1; d0 <= mat; ++i) {
		date d1(date(2015, 10, 22));
		d1.incr(12 * i / FREQ_SEMIANNUALLY, fms::datetime::UNIT_MONTHS).adjust(ROLL_MODIFIED_FOLLOWING, CALENDAR_NONE);
		d0 = d1;
		ensure(irlf1.cash(i) == 0.02*d1.diff_dcb(d0, DCB_30U_360));
	}

	using namespace fms::floating;

	leg_float<> irlf2;
	irlf2.fix(date(2014, 10, 22), 0.02);

	fms::datetime::date eff_{ date(2014, 10, 22) };

	ensure(eff_);

	date mat(eff_);
	mat.incr(3, UNIT_MONTHS);
	mat.adjust(ROLL_MODIFIED_FOLLOWING, CALENDAR_NONE);
	using namespace fms::pwflat;
	for (int i = 1; d0 <= mat; ++i) {
		date d1(date(2015, 10, 22));
		d1.incr(12 * i / FREQ_SEMIANNUALLY, fms::datetime::UNIT_MONTHS).adjust(ROLL_MODIFIED_FOLLOWING, CALENDAR_NONE);
		d0 = d1;
		ensure(irlf2.cash(i) == spot(d0,3,mat,0.02)*d1.diff_dcb(d0, DCB_30U_360));
	}

	//!!!zoewangforest add tests
}

#endif // _DEBUG