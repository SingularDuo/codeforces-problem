<h2><a href="https://codeforces.com/contest/1000/problem/F" target="_blank" rel="noopener noreferrer">1000F — One Occurrence</a></h2>

| | |
|---|---|
| **Difficulty** | 2400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1000F](https://codeforces.com/contest/1000/problem/F) |

## Topics
`data structures` `divide and conquer`

---

## Problem Statement

<div class="header"><div class="title">F. One Occurrence</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>768 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given an array $$$a$$$ consisting of $$$n$$$ integers, and $$$q$$$ queries to it. $$$i$$$-th query is denoted by two integers $$$l_i$$$ and $$$r_i$$$. For each query, you have to find <span class="tex-font-style-bf">any</span> integer that occurs <span class="tex-font-style-bf">exactly once</span> in the subarray of $$$a$$$ from index $$$l_i$$$ to index $$$r_i$$$ (a subarray is a contiguous subsegment of an array). For example, if $$$a = [1, 1, 2, 3, 2, 4]$$$, then for query $$$(l_i = 2, r_i = 6)$$$ the subarray we are interested in is $$$[1, 2, 3, 2, 4]$$$, and possible answers are $$$1$$$, $$$3$$$ and $$$4$$$; for query $$$(l_i = 1, r_i = 2)$$$ the subarray we are interested in is $$$[1, 1]$$$, and there is no such element that occurs exactly once.</p><p>Can you answer all of the queries?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$n$$$ ($$$1 \le n \le 5 \cdot 10^5$$$).</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$1 \le a_i \le 5 \cdot 10^5$$$).</p><p>The third line contains one integer $$$q$$$ ($$$1 \le q \le 5 \cdot 10^5$$$).</p><p>Then $$$q$$$ lines follow, $$$i$$$-th line containing two integers $$$l_i$$$ and $$$r_i$$$ representing $$$i$$$-th query ($$$1 \le l_i \le r_i \le n$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Answer the queries as follows:</p><p>If there is no integer such that it occurs in the subarray from index $$$l_i$$$ to index $$$r_i$$$ exactly once, print $$$0$$$. Otherwise print any such integer.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id000864278605871307" id="id009945448729961174" class="input-output-copier">Copy</div></div><pre id="id000864278605871307">6<br>1 1 2 3 2 4<br>2<br>2 6<br>1 2<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id004487657894387186" id="id005321909984041151" class="input-output-copier">Copy</div></div><pre id="id004487657894387186">4<br>0<br></pre></div></div></div>