<h2><a href="https://codeforces.com/contest/1398/problem/C" target="_blank" rel="noopener noreferrer">1398C — Good Subarrays</a></h2>

| | |
|---|---|
| **Difficulty** | 1600 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1398C](https://codeforces.com/contest/1398/problem/C) |

## Topics
`data structures` `dp` `math`

---

## Problem Statement

<div class="header"><div class="title">C. Good Subarrays</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given an array $$$a_1, a_2, \dots , a_n$$$ consisting of integers from $$$0$$$ to $$$9$$$. A subarray $$$a_l, a_{l+1}, a_{l+2}, \dots , a_{r-1}, a_r$$$ is good if the sum of elements of this subarray is equal to the length of this subarray ($$$\sum\limits_{i=l}^{r} a_i = r - l + 1$$$).</p><p>For example, if $$$a = [1, 2, 0]$$$, then there are $$$3$$$ good subarrays: $$$a_{1 \dots 1} = [1], a_{2 \dots 3} = [2, 0]$$$ and $$$a_{1 \dots 3} = [1, 2, 0]$$$.</p><p>Calculate the number of good subarrays of the array $$$a$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t$$$ ($$$1 \le t \le 1000$$$) — the number of test cases.</p><p>The first line of each test case contains one integer $$$n$$$ ($$$1 \le n \le 10^5$$$) — the length of the array $$$a$$$.</p><p>The second line of each test case contains a string consisting of $$$n$$$ decimal digits, where the $$$i$$$-th digit is equal to the value of $$$a_i$$$.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case print one integer — the number of good subarrays of the array $$$a$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id002343508979369857" id="id009646466048532852" class="input-output-copier">Copy</div></div><pre id="id002343508979369857">3
3
120
5
11011
6
600005
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008036402999294372" id="id005812375482529171" class="input-output-copier">Copy</div></div><pre id="id008036402999294372">3
6
1
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>The first test case is considered in the statement.</p><p>In the second test case, there are $$$6$$$ good subarrays: $$$a_{1 \dots 1}$$$, $$$a_{2 \dots 2}$$$, $$$a_{1 \dots 2}$$$, $$$a_{4 \dots 4}$$$, $$$a_{5 \dots 5}$$$ and $$$a_{4 \dots 5}$$$. </p><p>In the third test case there is only one good subarray: $$$a_{2 \dots 6}$$$.</p></div>