<h2><a href="https://codeforces.com/contest/1486/problem/D" target="_blank" rel="noopener noreferrer">1486D — Max Median</a></h2>

| | |
|---|---|
| **Difficulty** | 2100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1486D](https://codeforces.com/contest/1486/problem/D) |

## Topics
`binary search` `data structures` `dp`

---

## Problem Statement

<div class="header"><div class="title">D. Max Median</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are a given an array $$$a$$$ of length $$$n$$$. Find a subarray $$$a[l..r]$$$ with length at least $$$k$$$ with the largest median.</p><p>A median in an array of length $$$n$$$ is an element which occupies position number $$$\lfloor \frac{n + 1}{2} \rfloor$$$ after we sort the elements in non-decreasing order. For example: $$$median([1, 2, 3, 4]) = 2$$$, $$$median([3, 2, 1]) = 2$$$, $$$median([2, 1, 2, 1]) = 1$$$.</p><p>Subarray $$$a[l..r]$$$ is a contiguous part of the array $$$a$$$, i. e. the array $$$a_l,a_{l+1},\ldots,a_r$$$ for some $$$1 \leq l \leq r \leq n$$$, its length is $$$r - l + 1$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$k$$$ ($$$1 \leq k \leq n \leq 2 \cdot 10^5$$$).</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \leq a_i \leq n$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output one integer $$$m$$$ — the maximum median you can get.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005405349810877116" id="id008808212950250007" class="input-output-copier">Copy</div></div><pre id="id005405349810877116">5 3
1 2 3 2 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0026577208363012395" id="id008229389504797007" class="input-output-copier">Copy</div></div><pre id="id0026577208363012395">2</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id003684384846245251" id="id007972598935303739" class="input-output-copier">Copy</div></div><pre id="id003684384846245251">4 2
1 2 3 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0043943544824486935" id="id0030404029353631956" class="input-output-copier">Copy</div></div><pre id="id0043943544824486935">3</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example all the possible subarrays are $$$[1..3]$$$, $$$[1..4]$$$, $$$[1..5]$$$, $$$[2..4]$$$, $$$[2..5]$$$ and $$$[3..5]$$$ and the median for all of them is $$$2$$$, so the maximum possible median is $$$2$$$ too.</p><p>In the second example $$$median([3..4]) = 3$$$.</p></div>