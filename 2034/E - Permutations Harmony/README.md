<h2><a href="https://codeforces.com/contest/2034/problem/E" target="_blank" rel="noopener noreferrer">2034E — Permutations Harmony</a></h2>

| | |
|---|---|
| **Difficulty** | 2200 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2034E](https://codeforces.com/contest/2034/problem/E) |

## Topics
`combinatorics` `constructive algorithms` `greedy` `hashing` `math`

---

## Problem Statement

<div class="header"><div class="title">E. Permutations Harmony</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Rayan wants to present a gift to Reyhaneh to win her heart. However, Reyhaneh is particular and will only accept a <span class="tex-font-style-it">k-harmonic set of permutations</span>.</p><p>We define a <span class="tex-font-style-it">k-harmonic set of permutations</span> as a set of $$$k$$$ <span class="tex-font-style-bf">pairwise distinct</span> permutations $$$p_1, p_2, \ldots, p_k$$$ of size $$$n$$$ such that for every pair of indices $$$i$$$ and $$$j$$$ (where $$$1 \leq i, j \leq n$$$), the following condition holds:</p><p>$$$$$$ p_1[i] + p_2[i] + \ldots + p_k[i] = p_1[j] + p_2[j] + \ldots + p_k[j] $$$$$$</p><p>Your task is to help Rayan by either providing a valid <span class="tex-font-style-it">k-harmonic set of permutations</span> for given values of $$$n$$$ and $$$k$$$ or by determining that such a set does not exist.</p><p>We call a sequence of length $$$n$$$ a permutation if it contains every integer from $$$1$$$ to $$$n$$$ exactly once.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$t$$$ ($$$1 \leq t \leq 1000$$$), the number of test cases.</p><p>Each test case consists of two integers $$$n$$$ and $$$k$$$ ($$$1 \leq n, k \leq 10^5$$$). The sum of $$$n \cdot k$$$ over all test cases does not exceed $$$5 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, if a <span class="tex-font-style-it">k-harmonic set of permutations</span> exists, print <span class="tex-font-style-tt">YES</span> on the first line. Then, print $$$k$$$ lines, each containing a distinct permutation of the integers from $$$1$$$ to $$$n$$$.</p><p>If no such set exists, print <span class="tex-font-style-tt">NO</span> on the first line.</p><p>You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).</p><p>If multiple answers are possible, you can output any of them.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007096255949682042" id="id005681081507962439" class="input-output-copier">Copy</div></div><pre id="id007096255949682042"><div class="test-example-line test-example-line-even test-example-line-0">4</div><div class="test-example-line test-example-line-odd test-example-line-1">3 3</div><div class="test-example-line test-example-line-even test-example-line-2">4 2</div><div class="test-example-line test-example-line-odd test-example-line-3">5 1</div><div class="test-example-line test-example-line-even test-example-line-4">3 2</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00051440983590786304" id="id0006196071721262841" class="input-output-copier">Copy</div></div><pre id="id00051440983590786304">YES
1 2 3
2 3 1
3 1 2
YES
1 2 3 4
4 3 2 1
NO
YES
1 2 3
3 2 1
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In example 1, we have $$$p_1 = [1, 2, 3]$$$, $$$p_2 = [2, 3, 1]$$$, and $$$p_3 = [3, 1, 2]$$$. It's easy to see that $$$p_1[1] + p_2[1] + p_3[1] = p_1[2] + p_2[2] + p_3[2] = p_1[3] + p_2[3] + p_3[3] = 6$$$.</p><p>In example 2, we have $$$p_1 = [1, 2, 3, 4]$$$ and $$$p_2 = [4, 3, 2, 1]$$$. It's easy to see that $$$p_1[1] + p_2[1] = p_1[2] + p_2[2] = p_1[3] + p_2[3] = p_1[4] + p_2[4] = 5$$$.</p><p>In example 3, as there are five distinct elements in $$$p_1$$$, it's obvious that the answer is "No".</p></div>