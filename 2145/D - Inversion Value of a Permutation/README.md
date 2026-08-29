<h2><a href="https://codeforces.com/contest/2145/problem/D" target="_blank" rel="noopener noreferrer">2145D — Inversion Value of a Permutation</a></h2>

| | |
|---|---|
| **Difficulty** | 1800 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2145D](https://codeforces.com/contest/2145/problem/D) |

## Topics
`constructive algorithms` `dfs and similar` `dp`

---

## Problem Statement

<div class="header"><div class="title">D. Inversion Value of a Permutation</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>A permutation of length $$$n$$$ is an array of $$$n$$$ integers, where each number from $$$1$$$ to $$$n$$$ appears exactly once. An <span class="tex-font-style-it">inversion</span> in a permutation $$$p$$$ is a pair of indices $$$(i, j)$$$ such that $$$i  \lt  j$$$ and $$$p_i  \gt  p_j$$$.</p><p>For a permutation $$$p$$$, we define its <span class="tex-font-style-it">inversion value</span> as the number of its subsegments that contain at least one inversion. Formally, this is the number of pairs of integers $$$(l, r)$$$ ($$$1 \le l  \lt  r \le n$$$) for which there exists a pair of indices $$$(i, j)$$$ satisfying the following conditions: $$$l \le i  \lt  j \le r$$$ and $$$p_i  \gt  p_j$$$.</p><p>For example, for the permutation $$$[3, 1, 4, 2]$$$, the inversion value is $$$5$$$.</p><p>You are given two integers $$$n$$$ and $$$k$$$. Your task is to construct a permutation of length $$$n$$$ with an <span class="tex-font-style-bf">inversion value equal to exactly $$$k$$$</span>.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t$$$ ($$$1 \le t \le 500$$$) — the number of test cases.</p><p>Each test case consists of a single line containing two integers $$$n$$$ and $$$k$$$ ($$$2 \le n \le 30$$$; $$$0 \le k \le \dfrac{n(n-1)}{2}$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output the answer as follows:</p><ul> <li> if the desired permutation does not exist, output a single integer $$$0$$$; </li><li> otherwise, output $$$n$$$ distinct integers from $$$1$$$ to $$$n$$$ — the desired permutation. If there are multiple such permutations, you may output any of them. </li></ul></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0034870057220132944" id="id000936535010149806" class="input-output-copier">Copy</div></div><pre id="id0034870057220132944"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">4 5</div><div class="test-example-line test-example-line-even test-example-line-2">5 10</div><div class="test-example-line test-example-line-odd test-example-line-3">5 0</div><div class="test-example-line test-example-line-even test-example-line-4">6 8</div><div class="test-example-line test-example-line-odd test-example-line-5">3 1</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id002728121184719452" id="id006871827327560835" class="input-output-copier">Copy</div></div><pre id="id002728121184719452">3 1 4 2
5 4 3 2 1
1 2 3 4 5
2 3 5 6 1 4
0
</pre></div></div></div>