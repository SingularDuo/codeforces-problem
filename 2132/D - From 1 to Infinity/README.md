<h2><a href="https://codeforces.com/contest/2132/problem/D" target="_blank" rel="noopener noreferrer">2132D — From 1 to Infinity</a></h2>

| | |
|---|---|
| **Difficulty** | 1600 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2132D](https://codeforces.com/contest/2132/problem/D) |

## Topics
`binary search` `dp` `implementation` `math`

---

## Problem Statement

<div class="header"><div class="title">D. From 1 to Infinity</div><div class="time-limit"><div class="property-title">time limit per test</div>1.5 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Vadim wanted to understand the infinite sequence of digits that consists of the positive integers written consecutively from $$$1$$$ to infinity. That is, this sequence looks like $$$123456789101112131415 \ldots$$$</p><p>To avoid looking into infinity, Vadim cut this sequence at the $$$k$$$-th digit and discarded everything after it. Thus, exactly $$$k$$$ digits remained in the sequence. Help him find the sum of the digits in the remaining sequence.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test consists of several test cases. The first line contains a single integer $$$t$$$ $$$(1 \le t \le 2 \cdot 10^4)$$$ — the number of test cases. The following lines describe the test cases.</p><p>In a single line of each test case, there is an integer $$$k$$$ — the number of digits in the remaining sequence $$$(1 \le k \le 10^{15})$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each given $$$k$$$, output the sum of the digits in the sequence of length $$$k$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0024688046884358794" id="id008411871284861876" class="input-output-copier">Copy</div></div><pre id="id0024688046884358794"><div class="test-example-line test-example-line-even test-example-line-0">6</div><div class="test-example-line test-example-line-odd test-example-line-1">5</div><div class="test-example-line test-example-line-even test-example-line-2">10</div><div class="test-example-line test-example-line-odd test-example-line-3">13</div><div class="test-example-line test-example-line-even test-example-line-4">29</div><div class="test-example-line test-example-line-odd test-example-line-5">1000000000</div><div class="test-example-line test-example-line-even test-example-line-6">1000000000000000</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0013272913918574447" id="id00965721717865068" class="input-output-copier">Copy</div></div><pre id="id0013272913918574447">15
46
48
100
4366712386
4441049382716054
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample, the remaining sequence will be $$$12345$$$.</p><p>In the second sample, the remaining sequence will be $$$1234567891$$$.</p><p>In the third sample, the remaining sequence will be $$$1234567891011$$$.</p></div>