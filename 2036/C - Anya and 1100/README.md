<h2><a href="https://codeforces.com/contest/2036/problem/C" target="_blank" rel="noopener noreferrer">2036C — Anya and 1100</a></h2>

| | |
|---|---|
| **Difficulty** | 1100 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2036C](https://codeforces.com/contest/2036/problem/C) |

## Topics
`brute force` `implementation`

---

## Problem Statement

<div class="header"><div class="title">C. Anya and 1100</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>While rummaging through things in a distant drawer, Anya found a beautiful string $$$s$$$ consisting only of zeros and ones.</p><p>Now she wants to make it even more beautiful by performing $$$q$$$ operations on it.</p><p>Each operation is described by two integers $$$i$$$ ($$$1 \le i \le |s|$$$) and $$$v$$$ ($$$v \in \{0, 1\}$$$) and means that the $$$i$$$-th character of the string is assigned the value $$$v$$$ (that is, the assignment $$$s_i = v$$$ is performed).</p><p>But Anya loves the number $$$1100$$$, so after each query, she asks you to tell her whether the substring "<span class="tex-font-style-tt">1100</span>" is present in her string (i.e. there exist such $$$1 \le i \le |s| - 3$$$ that $$$s_{i}s_{i + 1}s_{i + 2}s_{i + 3} = \texttt{1100}$$$).</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t$$$ ($$$1 \leq t \leq 10^4$$$) — the number of test cases.</p><p>The first line of the test case contains the string $$$s$$$ ($$$1 \leq |s| \leq 2 \cdot 10^5$$$), consisting only of the characters "<span class="tex-font-style-tt">0</span>" and "<span class="tex-font-style-tt">1</span>". Here $$$|s|$$$ denotes the length of the string $$$s$$$.</p><p>The next line contains an integer $$$q$$$ ($$$1 \leq q \leq 2 \cdot 10^5$$$) — the number of queries.</p><p>The following $$$q$$$ lines contain two integers $$$i$$$ ($$$1 \leq i \leq |s|$$$) and $$$v$$$ ($$$v \in \{0, 1\}$$$), describing the query.</p><p>It is guaranteed that the sum of $$$|s|$$$ across all test cases does not exceed $$$2 \cdot 10^5$$$. It is also guaranteed that the sum of $$$q$$$ across all test cases does not exceed $$$2 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each query, output "<span class="tex-font-style-tt">YES</span>", if "<span class="tex-font-style-tt">1100</span>" is present in Anya's string; otherwise, output "<span class="tex-font-style-tt">NO</span>".</p><p>You can output the answer in any case (upper or lower). For example, the strings "<span class="tex-font-style-tt">yEs</span>", "<span class="tex-font-style-tt">yes</span>", "<span class="tex-font-style-tt">Yes</span>", and "<span class="tex-font-style-tt">YES</span>" will be recognized as positive responses.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0011745362492768163" id="id0022942114868930097" class="input-output-copier">Copy</div></div><pre id="id0011745362492768163"><div class="test-example-line test-example-line-even test-example-line-0">4</div><div class="test-example-line test-example-line-odd test-example-line-1">100</div><div class="test-example-line test-example-line-odd test-example-line-1">4</div><div class="test-example-line test-example-line-odd test-example-line-1">1 1</div><div class="test-example-line test-example-line-odd test-example-line-1">2 0</div><div class="test-example-line test-example-line-odd test-example-line-1">2 0</div><div class="test-example-line test-example-line-odd test-example-line-1">3 1</div><div class="test-example-line test-example-line-even test-example-line-2">1100000</div><div class="test-example-line test-example-line-even test-example-line-2">3</div><div class="test-example-line test-example-line-even test-example-line-2">6 1</div><div class="test-example-line test-example-line-even test-example-line-2">7 1</div><div class="test-example-line test-example-line-even test-example-line-2">4 1</div><div class="test-example-line test-example-line-odd test-example-line-3">111010</div><div class="test-example-line test-example-line-odd test-example-line-3">4</div><div class="test-example-line test-example-line-odd test-example-line-3">1 1</div><div class="test-example-line test-example-line-odd test-example-line-3">5 0</div><div class="test-example-line test-example-line-odd test-example-line-3">4 1</div><div class="test-example-line test-example-line-odd test-example-line-3">5 0</div><div class="test-example-line test-example-line-even test-example-line-4">0100</div><div class="test-example-line test-example-line-even test-example-line-4">4</div><div class="test-example-line test-example-line-even test-example-line-4">3 1</div><div class="test-example-line test-example-line-even test-example-line-4">1 1</div><div class="test-example-line test-example-line-even test-example-line-4">2 0</div><div class="test-example-line test-example-line-even test-example-line-4">2 1</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0026458231226744666" id="id009832324291382412" class="input-output-copier">Copy</div></div><pre id="id0026458231226744666">NO
NO
NO
NO
YES
YES
NO
NO
YES
YES
YES
NO
NO
NO
NO
</pre></div></div></div>