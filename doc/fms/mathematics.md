# Mathematics

Contrary to popular belief, stochastic processes are not needed
for financial modeling. All you need to know are algebras and
measureable functions. Positive measure with mass one show up,
but they are not the probability of anything.

## Outcomes

The set of everything that can happen, all possible _outcomes_, is
denoted by $\Omega$.  It is usually a collection of possible instrument
price trajectories but it could also include current and future news,
social media data, etc. No, really. It can be the set of EVERYTHING that
can happen. It may not be practical to implement, but math allows us to
think big.

## Algebras/Partitions/Partial Information

A subset of outcomes is an _event_. The outcome of rolling a die is
represented by a set: $\{1,2,3,4,5,6\}$. The event of rolling an even
number is the subset $\{2,4,6\}$.  An _algebra_ is a collection of sets
closed under complement and union. By
(De Morgan's laws)[http://en.wikipedia.org/wiki/De_Morgan's_laws],
algebras are also closed under intersection. These are natual axioms when
talking about an event not happening, or either of two events occuring.

A _partition_ is a disjoint union of subsets, $(A_j)_j$,
such that $\Omega = \cup_j A_j$ where $A_i\cap A_j =
\emptyset$ if $i\not= j$. For an algebra, $\mathscr{F}$,
$A\in\mathscr{F}$ is an _atom_ if $B\subseteq A$,
$B\in\mathscr{A}$ imply $B=A$ or $B=\emptyset$.

If an algebra $\mathscr{F}$ is finite the atoms form a partition.
The algebra $\{\emptyset,\Omega\}$ represents complete lack
of information.
The _power set_ $\mathscr{P}(\Omega) =
\{A:A\subseteq\Omega\}$ represents complete information.
Knowing which atom $\omega\in\Omega$ belongs to represents
_partial information_.
E.g., the partition $\{\{1,3,5\},\{2,4,6\}\}$ represents knowing whether
a die roll is even or odd.

## Measurable Functions

A function $X\colon\Omega\to\mathbb{R}$ is _measurable_ if
$\{\omega\in\Omega: X(\omega) \le x\}\in\mathscr{F}$ for all
$x\in\mathbb{R}$ If $\mathscr{F}$ is finite, measurable is the same as
being constant on atoms.

## (Finitely Additive) Measures

A _finitely additive measure_ is a function
$\Pi\colon\mathscr{F}\to\mathbb{R}$ such that
$\Pi(A\cup B) = \Pi(A) + \Pi(B)$ if $A\cap B = \emptyset$

-   The [vector space dual](http://en.wikipedia.org/wiki/Dual_space) of
    bounded measurable functions
-   The dual pairing is $\langle X,\Pi\rangle = \int_\Omega
    X\,d\Pi$
-   If $\mathscr{A}$ is finite the integral is just the sum over
    atoms
-   For $X\in B(\Omega,\mathscr{A})$ and $\Pi\in
    ba(\Omega,\mathscr{A})$ define $X\Pi\in
    ba(\Omega,\mathscr{A})$ by $\langle Y,X\Pi\rangle =
    \langle YX,\Pi\rangle$
-   $\Pi|_\mathscr{A}$ is the measure $\Pi$ restricted to
    the algebra $\mathscr{A}$
-   _Conditional expectation_ $E[X|\mathscr{A}]$ is defined by
    $\langle E[X|\mathscr{A}],\Pi\rangle = \langle
    X,\Pi|_\mathscr{A}\rangle$, $\Pi\in ba(\Omega)$
-   The
    [adjoint/dual/transpose](http://en.wikipedia.org/wiki/Dual_space) of
    conditional expectation is restriction

$(\mathscr{A}_t)_{t\in T}$ - Filtrations
------------------------------------------------

-   An increasing sequence of algebras
-   Represents information available over time
-   Consider flipping a coin: $T$,$H$,$H$,$\dots$
-   Model as $\omega\in[0,1)$ $\omega = .011\dots_2 =
    \sum_{j\gt0} \omega_j 2^{-j}$, $\omega_j
    \in\{0,1\}$
-   $\mathscr{A}_j = \{[\frac{i}{2^j},\frac{i+1}{2^j}) : 0\le
    i\lt 2^j\}$ represents knowing the first $j$ digits

Fundamental Theorem of Asset Pricing
------------------------------------

-   There is no arbitrage iff there exist positive scalar measures
    $(\Pi_j)$ with \begin{equation\*} X_j\Pi_j = (C_{j+1} +
    X_{j+1})\Pi_{j+1}|_{\mathscr{A}_j} \end{equation\*}
-   By induction \begin{equation} X_j\Pi_j = (\sum_{j\lt i\le
    k}C_i\Pi_i + X_k\Pi_k)|_{\mathscr{A}_j} \label{ftap}
    \end{equation}
-   $(\Pi_j)$ are unique if market is complete (Second fundamental
    theorem)
-   Never true for realistic models

FTAP easy direction
-------------------

-   Suppose there exist price deflators with $X_j\Pi_j = (C_{j+1}
    + X_{j+1})\Pi_{j+1}|_{\mathscr{A}_j}$
-   Using $A_{j+1} = \Delta_{j}\cdot C_{j+1} -
    \Gamma_{j+1}\cdot X_{j+1}$
-   \begin{align\*} \Delta_j\cdot X_j\Pi_j &=
    \underline{\Delta_j}\cdot(\underline{C_{j+1}} +
    X_{j+1})\Pi_{j+1}|_{\mathscr{A}_j}\\ &= (\mathbf{A_{j+1} +
    \underline{\Gamma_{j+1}}\cdot X_{j+1}})\Pi_{j+1} +
    \underline{\Delta_j}\cdot
    X_{j+1}\Pi_{j+1}|_{\mathscr{A}_j}\\ &= A_{j+1}\Pi_{j+1} +
    \mathbf{\Delta_{j+1}}\cdot
    X_{j+1}\Pi_{j+1}|_{\mathscr{A}_j}\\ \end{align\*}
-   By induction \begin{equation} \Delta_j\cdot X_j\Pi_j =
    \sum_{j\lt i\le k} A_i\Pi_i + \Delta_k\cdot
    X_k\Pi_k|_{\mathscr{A}_j} \label{ftdp} \end{equation}
-   $\sum_j\Gamma_j = 0$ and $A_i\ge0$, $i\gt0$ imply
    $0 = \sum_i A_i\Pi_i|_{\mathscr{A}_0}$ and $A_0\le
    0$.

FTAP hard direction
-------------------

-   Who cares?
-   No arbitrage implies deflators exist, but we can find plenty
    -   E.g., $X_t = (e^{rt}, se^{(r - \sigma^2/2)t + \sigma
        B_t})$, $\Pi_t = e^{-rt}P$,
    -   where $(B_t)$ is Brownian motion and $P$ is Weiner
        measure
    -   models a bond and non-dividend paying stock
-   The hard part is finding models that reflect market dynamics with
    parameters that can be fitted to market data
-   Finding arbitrage free models is much easier

Derivatives
-----------

-   Prices and cash flows satisfy $\color{blue}X_j\Pi_j =
    \sum_{j\lt i\le k}\color{red}C_i\Pi_i +
    \color{blue}X_k\Pi_k|_{\mathscr{A}_j}$
-   For any trades $(\Gamma_j)$, $\color{blue}\Delta_j\cdot
    \color{blue}X_j\Pi_j = \sum_{j\lt i\le k}
    \color{red}A_i\Pi_i + \color{blue}\Delta_k\cdot
    \color{blue}X_k\Pi_k|_{\mathscr{A}_j}$
-   The position determines the value $\color{blue}\Delta_j\cdot
    \color{blue}X_j$...
-   ...and the account determines the cash flows $\color{red}A_j$
    for a derivative instrument
-   This is how to create synthetic instruments

Delta Hedging
-------------

-   Assuming $\Pi_0 = 1$ and $\Delta_j$ is eventually zero
    $$ \Delta_0\cdot X_0 = \sum_{0\lt
    i}A_i\Pi_i|_{\mathscr{A}_0} $$
-   "The value of a derivative is the expected value of discounted cash
    flows"
-   _If_ a hedge exists the initial hedge is given by $$\Gamma_0 =
    \Delta_0 = \frac{\partial(\Delta_0\cdot X_0)}{\partial
    X_0} = \frac{\partial}{\partial X_0}E[\sum_{0\lt
    i}A_i\Pi_i]$$
-   For a one period model with $C_j = 0$ we could solve
    $\min_{\Gamma_0}||\Gamma_0\cdot X_1 - A_1||^2$ and get a
    measure of the hedging error

One Period Binomial Model
-------------------------

-   $\Omega = \{S^-,S^+\}$, $X_0 = (1,s)$,
    $X_1(\omega) = (R,\omega)$, $C_j = 0$
-   Bond with realized return $R$ and stock goes from $s$ to
    either $S^-$ or $S^+$
-   Find $\pi^-$ and $\pi^+$ such that $(1,s) =
    (R,S^-)\pi^- + (R,S^+)\pi^+$
-   $\pi^- = (S^+/R - s)/(S^+ - S^-)$, $\pi^+ = (s -
    S^-/R)/(S^+ - S^-)$
-   Derivative pays $V(\omega)$ at time 1 for some function $V$
-   There exists $\Gamma_0 = (m,n)$ such that $\Gamma_0\cdot
    X_1 = V$
-   Solve $mR + nsd = V(S_-)$, $mR + nsu = V(S_+)$ for
    $m,n$
-   $n = (V(S_+)-V(S_-))/(S_+-S_-)$, and $$ v = m + ns =
    \frac{1}{R}\left(\frac{S_+-Rs}{S_+-S_-}V(S_-)+\frac{Rs -
    S_-}{S_+-S_-}V(S_+)\right) $$

Example: Put-Call Parity
------------------------

-   $T = \{0,1\}$, $\Omega = [0,\infty)$, $\mathscr{A}_0
    = \{\Omega\}$, $\mathscr{A}_1 = \mathscr{P}(\Omega)$,
    -   $X_0 = (1,s,c,p)$, $X_1(\omega) = (R,\omega,0,0)$,
    -   $C_1(\omega) = (0,0,\max\{\omega - k,0\},\max\{k -
        \omega,0\})$
-   Models a bond with realized return $R$, a stock that can have
    any non-negative value, and a call and put both struck at $k$.
-   No arbitarge implies $$(1,s,c,p) = \langle
    (R,\omega,\max\{\omega - k,0\},\max\{k -
    \omega,0\}),\Pi\rangle$$
-   Taking $\Gamma_0 = (k/R, -1, 1, -1)$ yields $k/R - s + c - p
    = \langle k - \omega + \max\{\omega - k,0\} - \max\{k -
    \omega,0\}),\Pi\rangle = 0$
-   Put-call parity: $c - p = s - k/R$
-   Don't really need a model for this, but it illustrates how to use
    the framework

Example: Cost of Carry
----------------------

-   $T = \{0,1\}$, $\Omega = [0,\infty)$, $\mathscr{A}_0
    = \{\Omega\}$, $\mathscr{A}_1 = \mathscr{P}(\Omega)$,
    -   $X_0 = (1,s,0)$, $X_1(\omega) = (R,\omega,0)$
    -   $C_1(\omega) = (0, 0, \omega - f)$
-   Models a bond with realized return $R$, a stock that can have
    any non-negative value, and an at-the-money forward
-   Forwards have price zero at expiration
-   No arbitarge implies $(1,s,0) = \langle
    (R,\omega,\omega-f),\Pi\rangle$ so $1 = \langle
    R,\Pi\rangle$, $s = \langle \omega,\Pi\rangle$, and $0
    = s - f/R$.
-   Cost-of-carry:$f = Rs$
-   Also don't really need a model for this

A Multiperiod Model
-------------------

-   $\Omega = [0,\infty)^n$
-   $X_0 = (1,s,0)$, $X_j = (R_j, \omega_j,
    \phi_j(\omega_j))$, $X_n = (R_n, \omega_n, 0)$
-   $C_j = 0$, $0\le j\lt n$, $C_n = (0, 0, \omega_n -
    f)$
-   Multiperiod stock and foward contract
-   The $\phi_j$ are determined by the no arbitrage condition
-   $\langle R_j,\Pi_j\rangle = \langle R_n, \Pi_n\rangle$
-   $\langle \omega_j, \Pi_j\rangle = \langle \omega_n,
    \Pi_n\rangle$
-   $\langle \phi_j(\omega_j), \Pi_j\rangle = \langle
    \omega_n - f, \Pi_n\rangle = \langle \omega_j -
    fR_n/R_j,\Pi_j\rangle$,
-   so $\phi_j(\omega_j) = \omega_j - fR_n/R_j$

Fixed Dividends
---------------

-   $\Omega = [0,\infty)^n$
-   $X_0 = (1,s,0)$, $X_j = (R_j, \omega_j,
    \phi_j(\omega_j))$, $X_n = (R_n, \omega_n, 0)$
-   $C_0 = 0$, $C_j = (0,d_j,0)$, $0\lt j\lt n$,
    $C_n = (0, d_n, \omega_n - f)$
-   Multiperiod stock paying dividends and foward contract
-   The $\phi_j$ are determined by the no arbitrage condition
-   $\langle R_j,\Pi_j\rangle = \langle R_n, \Pi_n\rangle$
-   $\langle \omega_j, \Pi_j\rangle = \sum_{j\lt k\lt
    n}\langle d_k, \Pi_k\rangle + \langle \omega_n + d_n,
    \Pi_n\rangle$
-   $\langle \phi_j(\omega_j), \Pi_j\rangle = \langle
    \omega_n - f, \Pi_n\rangle = \langle \omega_j -
    \sum_{j\lt k\le n}d_kR_n/R_k - fR_n/R_j,\Pi_j\rangle$,
-   so $\phi_j(\omega_j) = \omega_j - R_N(f/R_j +
    \sum_{j\lt k\le n}d_k/R_k)$

General Models
--------------

-   Specify a probability measure $P$ on $\Omega$
-   Choose $\pi_j\in B(\Omega,\mathscr{A}_j)$ and let
    $\Pi_j = \pi_jP|_{\mathscr{A}_j}$
-   Arbitrage free if $X_j\Pi_j = (C_{j+1} +
    X_{j+1})\Pi_{j+1}|_{\mathscr{A}_j}$
-   Customary to assume $\mathscr{A}_0 = \{\emptyset,\Omega\}$
    and $\pi_0 = 1$
-   The cash flows are usually specified by the market
-   The difficult part is specifying the prices and deflators

Canonical Price Deflator
------------------------

-   If $X_t = R(t)$ is deterministic and $C_t = 0$ then
    $\Pi_t = R(t)^{-1}P|_{\mathscr{A}_t}$ for any probability
    measure $P$ is a deflator for that single instrument
-   Assume for each time there is an instrument with $X_j = 1$ and
    $C_{j+1} = R_j$
-   $R_j$ is the _short realized return_ over $t_j$ to
    $t_{j+1}$
-   Define _canonical price deflators_ $$\Pi_j = (R_0\cdots
    R_{j-1})^{-1}P|_{\mathscr{A}_j}$$
-   Easy to show $\Pi_j = R_j\Pi_{j+1}|_{\mathscr{A}_j}$
-   Note $\Pi_j$ is $\mathscr{A}_{j-1}$ measurable (aka
    _predictable_)
-   There are many possible deflators, but this is canonnical

Zero Coupon Bonds
-----------------

-   A zero coupon bond maturing at $u$ has $X_0 = D(u)$ and
    $C_u = 1$
-   $D(u)\Pi_0 = \Pi_u|_{\mathscr{A}_0}$ so $D(u) =
    \Pi_u(\Omega)$
-   Let $D_t(u)$ be the price at time $t$
-   $D_t(u)\Pi_t = \Pi_u|_{\mathscr{A}_t}$ so $$ D_t(u) =
    \Pi_u/\Pi_t|_{\mathscr{A}_t} = \Pi_{t\le s\lt
    u}R_s^{-1}P|_{\mathscr{A}_t} $$

Forward Rate Agreements
-----------------------

-   have price $X_0 = 0$ and two cash flows
    -   $C_u = -1$, $C_v = 1 + F(u,v)\delta_{u,v}$
-   $\delta_{u,v}$ is the _day count fraction_ that is
    approximately $v - u$ in years depending on the [day count
    convention](http://en.wikipedia.org/wiki/Day_count_convention)
-   Since $0 = -D(u) + (1 + F(u,v)\delta_{u,v})D(v)$ we have $$
    F(u,v) = \frac{1}{\delta_{u,v}}\left(\frac{D(u)}{D(v)} -
    1\right) =
    \frac{1}{\delta_{u,v}}\left(\frac{\Pi_u}{\Pi_v}\bigr|_{\mathscr{A}_0}
    - 1\right) $$
-   Let $F_t(u,v)$ be the forward at time $t$ over $[u,v]$
-   Since $X_t = 0 = -D_t(u) + (1 +
    F_t(u,v)\delta_{u,v})D_t(v)$ we have $$ F_t(u,v) =
    \frac{1}{\delta_{u,v}}\left(\frac{D_t(u)}{D_t(v)} - 1\right)
    =
    \frac{1}{\delta_{u,v}}\left(\frac{\Pi_u}{\Pi_v}\bigr|_{\mathscr{A}_t}
    - 1\right) $$

Forward Rate Agreements w/o Notional
------------------------------------

-   Can also be specified as a single cash flow
-   price $X_0 = 0$ and forward $f(u,v)$ with
    -   $C_v = (F_u(u,v) - f(u,v))\delta_{u,v}$
-   Prevailing forward rate at start of period versus fixed
-   Note $0 = (F_u(u,v) -
    f(u,v))\delta_{u,v}\Pi_v|_{\mathscr{A}_0} = (\Pi_u -
    \Pi_v - f(u,v)\delta{u,v})|_{\mathscr{A}_0}$
-   and $F_0(u,v)\delta_{u,v}\Pi_v|_{\mathscr{A}_0} = (\Pi_u
    - \Pi_v)|_{\mathscr{A}_0}$
-   so $f(u,v) = F_0(u,v)$
-   These two contracts have very different risk profiles

Counterparty Risk
-----------------

-   Assume default time $T$ and recovery $R$ on remaining cash
    flows
-   $R$ assumed to be a constant, $T$ is a random variable
-   Assume $T$ is independent of the deflators
-   Augment sample space to $\Omega' = \Omega\times [0,\infty)$
-   Augment filtration to $\mathscr{A}_t' = \mathscr{A}_t \times
    \mathscr{B}_t$,
-   Where $B_t$ contains the set $(t,\infty)$ and any
    $B\subset [0,t]$
-   At time $t$ we either know the default time exactly or only that
    it has some value greater than $t$


