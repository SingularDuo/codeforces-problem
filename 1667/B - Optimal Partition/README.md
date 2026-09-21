<h2><a href="https://codeforces.com/contest/1667/problem/B" target="_blank" rel="noopener noreferrer">1667B — Optimal Partition</a></h2>

| | |
|---|---|
| **Difficulty** | 2100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1667B](https://codeforces.com/contest/1667/problem/B) |

## Topics
`data structures` `dp`

---

## Problem Statement

<div class="header"><div class="title">B. Optimal Partition</div><div class="time-limit"><div class="property-title">time limit per test</div>4 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given an array $$$a$$$ consisting of $$$n$$$ integers. You should divide $$$a$$$ into continuous non-empty subarrays (there are $$$2^{n-1}$$$ ways to do that).</p><p>Let $$$s=a_l+a_{l+1}+\ldots+a_r$$$. The value of a subarray $$$a_l, a_{l+1}, \ldots, a_r$$$ is: </p><ul> <li> $$$(r-l+1)$$$ if $$$s \gt 0$$$,</li><li> $$$0$$$ if $$$s=0$$$,</li><li> $$$-(r-l+1)$$$ if $$$s \lt 0$$$. </li></ul> What is the maximum sum of values you can get with a partition?</div><div class="input-specification"><div class="section-title">Input</div><p>The input consists of multiple test cases. The first line contains a single integer $$$t$$$ ($$$1 \le t \le 5 \cdot 10^5$$$) — the number of test cases. The description of the test cases follows.</p><p>The first line of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 5 \cdot 10^5$$$).</p><p>The second line of each test case contains $$$n$$$ integers $$$a_1$$$, $$$a_2$$$, ..., $$$a_n$$$ ($$$-10^9 \le a_i \le 10^9$$$).</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$5 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case print a single integer — the maximum sum of values you can get with an optimal parition.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005990392380958038" id="id0024384392553211975" class="input-output-copier">Copy</div></div><pre id="id005990392380958038"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">3</div><div class="test-example-line test-example-line-odd test-example-line-1">1 2 -3</div><div class="test-example-line test-example-line-even test-example-line-2">4</div><div class="test-example-line test-example-line-even test-example-line-2">0 -2 3 -4</div><div class="test-example-line test-example-line-odd test-example-line-3">5</div><div class="test-example-line test-example-line-odd test-example-line-3">-1 -2 3 -1 -1</div><div class="test-example-line test-example-line-even test-example-line-4">6</div><div class="test-example-line test-example-line-even test-example-line-4">-1 2 -3 4 -5 6</div><div class="test-example-line test-example-line-odd test-example-line-5">7</div><div class="test-example-line test-example-line-odd test-example-line-5">1 -1 -1 1 -1 -1 1</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008004138449285235" id="id007021067544462571" class="input-output-copier">Copy</div></div><pre id="id008004138449285235">1
2
1
6
-1
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>Test case $$$1$$$: one optimal partition is $$$[1, 2]$$$, $$$[-3]$$$. $$$1+2 \gt 0$$$ so the value of $$$[1, 2]$$$ is $$$2$$$. $$$-3 \lt 0$$$, so the value of $$$[-3]$$$ is $$$-1$$$. $$$2+(-1)=1$$$.</p><p>Test case $$$2$$$: the optimal partition is $$$[0, -2, 3]$$$, $$$[-4]$$$, and the sum of values is $$$3+(-1)=2$$$.</p></div>