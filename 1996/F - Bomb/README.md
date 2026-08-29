<h2><a href="https://codeforces.com/contest/1996/problem/F" target="_blank" rel="noopener noreferrer">1996F — Bomb</a></h2>

| | |
|---|---|
| **Difficulty** | 1900 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1996F](https://codeforces.com/contest/1996/problem/F) |

## Topics
`binary search` `greedy` `math`

---

## Problem Statement

<div class="header"><div class="title">F. Bomb</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Sparkle gives you two arrays $$$a$$$ and $$$b$$$ of length $$$n$$$. Initially, your score is $$$0$$$. In one operation, you can choose an integer $$$i$$$ and add $$$a_i$$$ to your score. Then, you must set $$$a_i$$$ = $$$\max(0, a_i - b_i)$$$.</p><p>You only have time to perform $$$k$$$ operations before Sparkle sets off a nuclear bomb! What is the maximum score you can acquire after $$$k$$$ operations?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains $$$t$$$ ($$$1 \leq t \leq 1000$$$) — the number of test cases.</p><p>The first line of each test case contains $$$n$$$ and $$$k$$$ ($$$1 \leq n \leq 2 \cdot 10^5, 1 \leq k \leq 10^9$$$) — the length of the arrays and the number of operations you can perform.</p><p>The following line contains $$$n$$$ integers $$$a_1, a_2, ... a_n$$$ ($$$1 \leq a_i \leq 10^9$$$).</p><p>The following line contains $$$n$$$ integers $$$b_1, b_2, ... b_n$$$ ($$$1 \leq b_i \leq 10^9$$$).</p><p>It is guaranteed that the sum of $$$n$$$ for all test cases does not exceed $$$2 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output an integer, the maximum score you can acquire after $$$k$$$ operations.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0019663321879155427" id="id0024142848641096193" class="input-output-copier">Copy</div></div><pre id="id0019663321879155427"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">3 4</div><div class="test-example-line test-example-line-odd test-example-line-1">5 6 7</div><div class="test-example-line test-example-line-odd test-example-line-1">2 3 4</div><div class="test-example-line test-example-line-even test-example-line-2">5 9</div><div class="test-example-line test-example-line-even test-example-line-2">32 52 68 64 14</div><div class="test-example-line test-example-line-even test-example-line-2">18 14 53 24 8</div><div class="test-example-line test-example-line-odd test-example-line-3">5 1000</div><div class="test-example-line test-example-line-odd test-example-line-3">1 2 3 4 5</div><div class="test-example-line test-example-line-odd test-example-line-3">5 4 3 2 1</div><div class="test-example-line test-example-line-even test-example-line-4">1 1000000</div><div class="test-example-line test-example-line-even test-example-line-4">1000000</div><div class="test-example-line test-example-line-even test-example-line-4">1</div><div class="test-example-line test-example-line-odd test-example-line-5">10 6</div><div class="test-example-line test-example-line-odd test-example-line-5">3 3 5 10 6 8 6 8 7 7</div><div class="test-example-line test-example-line-odd test-example-line-5">6 1 7 4 1 1 8 9 3 1</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id000994464569059067" id="id009233324890815154" class="input-output-copier">Copy</div></div><pre id="id000994464569059067">21
349
27
500000500000
47
</pre></div></div></div>