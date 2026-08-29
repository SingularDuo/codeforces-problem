<h2><a href="https://codeforces.com/contest/2044/problem/E" target="_blank" rel="noopener noreferrer">2044E — Insane Problem</a></h2>

| | |
|---|---|
| **Difficulty** | 1300 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2044E](https://codeforces.com/contest/2044/problem/E) |

## Topics
`binary search` `greedy` `implementation` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">E. Insane Problem</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Wave is given five integers $$$k$$$, $$$l_1$$$, $$$r_1$$$, $$$l_2$$$, and $$$r_2$$$. Wave wants you to help her count the number of ordered pairs $$$(x, y)$$$ such that all of the following are satisfied:</p><ul> <li> $$$l_1 \leq x \leq r_1$$$. </li><li> $$$l_2 \leq y \leq r_2$$$. </li><li> There exists a non-negative integer $$$n$$$ such that $$$\frac{y}{x} = k^n$$$. </li></ul></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 10^4$$$) — the number of test cases.</p><p>The only line of each test case contains five integers $$$k$$$, $$$l_1$$$, $$$r_1$$$, $$$l_2$$$, and $$$r_2$$$ ($$$2 \leq k \leq 10^9, 1 \leq l_1 \leq r_1 \leq 10^9, 1 \leq l_2 \leq r_2 \leq 10^9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output the number of matching ordered pairs $$$(x, y)$$$ on a new line.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id003552721397270452" id="id005592703255977444" class="input-output-copier">Copy</div></div><pre id="id003552721397270452"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">2 2 6 2 12</div><div class="test-example-line test-example-line-even test-example-line-2">2 1 1000000000 1 1000000000</div><div class="test-example-line test-example-line-odd test-example-line-3">3 5 7 15 63</div><div class="test-example-line test-example-line-even test-example-line-4">1000000000 1 5 6 1000000000</div><div class="test-example-line test-example-line-odd test-example-line-5">15 17 78 2596 20914861</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0047609752434707375" id="id0020187316840627534" class="input-output-copier">Copy</div></div><pre id="id0047609752434707375">12
1999999987
6
1
197
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the third test case, the matching ordered pairs are the following: </p><ul> <li> $$$(5,15)$$$ </li><li> $$$(5,45)$$$ </li><li> $$$(6,18)$$$ </li><li> $$$(6,54)$$$ </li><li> $$$(7,21)$$$ </li><li> $$$(7,63)$$$ </li></ul><p>In the fourth test case, the only valid ordered pair is $$$(1,1\,000\,000\,000)$$$</p></div>