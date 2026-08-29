<h2><a href="https://codeforces.com/contest/1732/problem/C2" target="_blank" rel="noopener noreferrer">1732C2 — Sheikh (Hard Version)</a></h2>

| | |
|---|---|
| **Difficulty** | 2100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1732C2](https://codeforces.com/contest/1732/problem/C2) |

## Topics
`binary search` `bitmasks` `brute force` `greedy` `implementation` `two pointers`

---

## Problem Statement

<div class="header"><div class="title">C2. Sheikh (Hard Version)</div><div class="time-limit"><div class="property-title">time limit per test</div>4 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p><span class="tex-font-style-bf">This is the hard version of the problem. The only difference is that in this version $$$q = n$$$.</span></p><p>You are given an array of integers $$$a_1, a_2, \ldots, a_n$$$.</p><p>The cost of a subsegment of the array $$$[l, r]$$$, $$$1 \leq l \leq r \leq n$$$, is the value $$$f(l, r) = \operatorname{sum}(l, r) - \operatorname{xor}(l, r)$$$, where $$$\operatorname{sum}(l, r) = a_l + a_{l+1} + \ldots + a_r$$$, and $$$\operatorname{xor}(l, r) = a_l \oplus a_{l+1} \oplus \ldots \oplus a_r$$$ ($$$\oplus$$$ stands for <a href="https://en.wikipedia.org/wiki/Bitwise_operation#XOR">bitwise XOR</a>).</p><p>You will have $$$q$$$ queries. Each query is given by a pair of numbers $$$L_i$$$, $$$R_i$$$, where $$$1 \leq L_i \leq R_i \leq n$$$. You need to find the subsegment $$$[l, r]$$$, $$$L_i \leq l \leq r \leq R_i$$$, with maximum value $$$f(l, r)$$$. If there are several answers, then among them you need to find a subsegment with the minimum length, that is, the minimum value of $$$r - l + 1$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test consists of multiple test cases. The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 10^4$$$) — the number of test cases. The description of test cases follows.</p><p>The first line of each test case contains two integers $$$n$$$ and $$$q$$$ ($$$1 \leq n \leq 10^5$$$, $$$q = n$$$) — the length of the array and the number of queries.</p><p>The second line of each test case contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$0 \leq a_i \leq 10^9$$$) — array elements.</p><p>$$$i$$$-th of the next $$$q$$$ lines of each test case contains two integers $$$L_i$$$ and $$$R_i$$$ ($$$1 \leq L_i \leq R_i \leq n$$$) — the boundaries in which we need to find the segment.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2 \cdot 10^5$$$.</p><p>It is guaranteed that $$$L_1 = 1$$$ and $$$R_1 = n$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case print $$$q$$$ pairs of numbers $$$L_i \leq l \leq r \leq R_i$$$ such that the value $$$f(l, r)$$$ is maximum and among such the length $$$r - l + 1$$$ is minimum. If there are several correct answers, print any of them.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004279165411608653" id="id007329048667488925" class="input-output-copier">Copy</div></div><pre id="id004279165411608653"><div class="test-example-line test-example-line-even test-example-line-0">6</div><div class="test-example-line test-example-line-odd test-example-line-1">1 1</div><div class="test-example-line test-example-line-odd test-example-line-1">0</div><div class="test-example-line test-example-line-odd test-example-line-1">1 1</div><div class="test-example-line test-example-line-even test-example-line-2">2 2</div><div class="test-example-line test-example-line-even test-example-line-2">5 10</div><div class="test-example-line test-example-line-even test-example-line-2">1 2</div><div class="test-example-line test-example-line-even test-example-line-2">2 2</div><div class="test-example-line test-example-line-odd test-example-line-3">3 3</div><div class="test-example-line test-example-line-odd test-example-line-3">0 2 4</div><div class="test-example-line test-example-line-odd test-example-line-3">1 3</div><div class="test-example-line test-example-line-odd test-example-line-3">1 2</div><div class="test-example-line test-example-line-odd test-example-line-3">2 3</div><div class="test-example-line test-example-line-even test-example-line-4">4 4</div><div class="test-example-line test-example-line-even test-example-line-4">0 12 8 3</div><div class="test-example-line test-example-line-even test-example-line-4">1 4</div><div class="test-example-line test-example-line-even test-example-line-4">1 3</div><div class="test-example-line test-example-line-even test-example-line-4">2 4</div><div class="test-example-line test-example-line-even test-example-line-4">2 3</div><div class="test-example-line test-example-line-odd test-example-line-5">5 5</div><div class="test-example-line test-example-line-odd test-example-line-5">21 32 32 32 10</div><div class="test-example-line test-example-line-odd test-example-line-5">1 5</div><div class="test-example-line test-example-line-odd test-example-line-5">1 4</div><div class="test-example-line test-example-line-odd test-example-line-5">1 3</div><div class="test-example-line test-example-line-odd test-example-line-5">2 5</div><div class="test-example-line test-example-line-odd test-example-line-5">3 5</div><div class="test-example-line test-example-line-even test-example-line-6">7 7</div><div class="test-example-line test-example-line-even test-example-line-6">0 1 0 1 0 1 0</div><div class="test-example-line test-example-line-even test-example-line-6">1 7</div><div class="test-example-line test-example-line-even test-example-line-6">3 6</div><div class="test-example-line test-example-line-even test-example-line-6">2 5</div><div class="test-example-line test-example-line-even test-example-line-6">1 4</div><div class="test-example-line test-example-line-even test-example-line-6">4 7</div><div class="test-example-line test-example-line-even test-example-line-6">2 6</div><div class="test-example-line test-example-line-even test-example-line-6">2 7</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00685451010105395" id="id007686156739199745" class="input-output-copier">Copy</div></div><pre id="id00685451010105395">1 1
1 1
2 2
1 1
1 1
2 2
2 3
2 3
2 3
2 3
2 3
2 3
2 3
2 3
3 4
2 4
4 6
2 4
2 4
4 6
2 4
2 4
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In all test cases, the first query is considered.</p><p>In the first test case, $$$f(1, 1) = 0 - 0 = 0$$$.</p><p>In the second test case, $$$f(1, 1) = 5 - 5 = 0$$$, $$$f(2, 2) = 10 - 10 = 0$$$. Note that $$$f(1, 2) = (10 + 5) - (10 \oplus 5) = 0$$$, but we need to find a subsegment with the minimum length among the maximum values of $$$f(l, r)$$$. So, only segments $$$[1, 1]$$$ and $$$[2, 2]$$$ are the correct answers.</p><p>In the fourth test case, $$$f(2, 3) = (12 + 8) - (12 \oplus 8) = 16$$$. </p><p>There are two correct answers in the fifth test case, since $$$f(2, 3) = f(3, 4)$$$ and their lengths are equal.</p></div>