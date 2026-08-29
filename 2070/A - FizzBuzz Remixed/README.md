<h2><a href="https://codeforces.com/contest/2070/problem/A" target="_blank" rel="noopener noreferrer">2070A — FizzBuzz Remixed</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2070A](https://codeforces.com/contest/2070/problem/A) |

## Topics
`brute force` `math`

---

## Problem Statement

<div class="header"><div class="title">A. FizzBuzz Remixed</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>FizzBuzz is one of the most well-known problems from coding interviews. In this problem, we will consider a remixed version of FizzBuzz:</p><p><span class="tex-font-style-it">Given an integer $$$n$$$, process all integers from $$$0$$$ to $$$n$$$. For every integer such that its remainders modulo $$$3$$$ and modulo $$$5$$$ are the same (so, for every integer $$$i$$$ such that $$$i \bmod 3 = i \bmod 5$$$), print</span> <span class="tex-font-style-tt">FizzBuzz</span>.</p><p>However, you don't have to solve it. Instead, given the integer $$$n$$$, you have to report how many times the correct solution to that problem will print <span class="tex-font-style-tt">FizzBuzz</span>.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases.</p><p>Each test case contains one line consisting of one integer $$$n$$$ ($$$0 \le n \le 10^9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, print one integer — the number of times the correct solution will print <span class="tex-font-style-tt">FizzBuzz</span> with the given value of $$$n$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008344686329179387" id="id004588498830968061" class="input-output-copier">Copy</div></div><pre id="id008344686329179387"><div class="test-example-line test-example-line-even test-example-line-0">7</div><div class="test-example-line test-example-line-odd test-example-line-1">0</div><div class="test-example-line test-example-line-even test-example-line-2">5</div><div class="test-example-line test-example-line-odd test-example-line-3">15</div><div class="test-example-line test-example-line-even test-example-line-4">42</div><div class="test-example-line test-example-line-odd test-example-line-5">1337</div><div class="test-example-line test-example-line-even test-example-line-6">17101997</div><div class="test-example-line test-example-line-odd test-example-line-7">998244353</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id003742856346589106" id="id006162132433588953" class="input-output-copier">Copy</div></div><pre id="id003742856346589106">1
3
4
9
270
3420402
199648872
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, the solution will print <span class="tex-font-style-tt">FizzBuzz</span> for the integer $$$0$$$.</p><p>In the second test case, the solution will print <span class="tex-font-style-tt">FizzBuzz</span> for the integers $$$0, 1, 2$$$.</p><p>In the third test case, the solution will print <span class="tex-font-style-tt">FizzBuzz</span> for the integers $$$0, 1, 2, 15$$$.</p></div>