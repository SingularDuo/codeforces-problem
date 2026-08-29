<h2><a href="https://codeforces.com/contest/2108/problem/B" target="_blank" rel="noopener noreferrer">2108B — SUMdamental Decomposition</a></h2>

| | |
|---|---|
| **Difficulty** | 1300 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2108B](https://codeforces.com/contest/2108/problem/B) |

## Topics
`bitmasks` `constructive algorithms` `greedy` `implementation` `math`

---

## Problem Statement

<div class="header"><div class="title">B. SUMdamental Decomposition</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p> </p><p>On a recent birthday, your best friend Maurice gave you a pair of numbers $$$n$$$ and $$$x$$$, and asked you to construct an array of <span class="tex-font-style-bf">positive</span> numbers $$$a$$$ of length $$$n$$$ such that $$$a_1 \oplus a_2 \oplus \cdots \oplus a_n = x$$$ $$$^{\text{∗}}$$$. </p><p>This task seemed too simple to you, and therefore you decided to give Maurice a return gift by constructing an array among all such arrays that has the smallest sum of its elements. You immediately thought of a suitable array; however, since writing it down turned out to be too time-consuming, Maurice will have to settle for just the sum of its elements.</p><div class="statement-footnote"><p>$$$^{\text{∗}}$$$$$$\oplus$$$ denotes the <a href="https://en.wikipedia.org/wiki/Bitwise_operation#XOR">bitwise XOR operation</a>. </p></div></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. </p><p>Each test case consists of a single line containing a pair of numbers $$$n$$$ and $$$x$$$ ($$$1 \le n \le 10^9, \; 0 \le x \le 10^9$$$) — the numbers given to you by Maurice.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output your gift to Maurice — the sum of the elements of the array that satisfies all the described properties. If a suitable array does not exist, output $$$-1$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004007104599336363" id="id004943318035207511" class="input-output-copier">Copy</div></div><pre id="id004007104599336363"><div class="test-example-line test-example-line-even test-example-line-0">8</div><div class="test-example-line test-example-line-odd test-example-line-1">2 1</div><div class="test-example-line test-example-line-even test-example-line-2">3 6</div><div class="test-example-line test-example-line-odd test-example-line-3">1 0</div><div class="test-example-line test-example-line-even test-example-line-4">2 0</div><div class="test-example-line test-example-line-odd test-example-line-5">5 0</div><div class="test-example-line test-example-line-even test-example-line-6">2 27</div><div class="test-example-line test-example-line-odd test-example-line-7">15 43</div><div class="test-example-line test-example-line-even test-example-line-8">12345678 9101112</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0012801374962172507" id="id009100351995117206" class="input-output-copier">Copy</div></div><pre id="id0012801374962172507">5
8
-1
2
8
27
55
21446778
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, one of the suitable arrays is $$$[2, 3]$$$. It can be shown that it is impossible to achieve a smaller sum of array elements.</p><p>In the second case, one of the suitable arrays is $$$[1, 3, 4]$$$. It can also be shown that this is the optimal amount.</p></div>