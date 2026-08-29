<h2><a href="https://codeforces.com/contest/1370/problem/E" target="_blank" rel="noopener noreferrer">1370E — Binary Subsequence Rotation</a></h2>

| | |
|---|---|
| **Difficulty** | 2100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1370E](https://codeforces.com/contest/1370/problem/E) |

## Topics
`binary search` `constructive algorithms` `data structures` `greedy`

---

## Problem Statement

<div class="header"><div class="title">E. Binary Subsequence Rotation</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Naman has two binary strings $$$s$$$ and $$$t$$$ of length $$$n$$$ (a binary string is a string which only consists of the characters "<span class="tex-font-style-tt">0</span>" and "<span class="tex-font-style-tt">1</span>"). He wants to convert $$$s$$$ into $$$t$$$ using the following operation as few times as possible.</p><p>In one operation, he can choose any subsequence of $$$s$$$ and rotate it clockwise once.</p><p>For example, if $$$s = 1\textbf{1}101\textbf{00}$$$, he can choose a subsequence corresponding to indices ($$$1$$$-based) $$$\{2, 6, 7 \}$$$ and rotate them clockwise. The resulting string would then be $$$s = 1\textbf{0}101\textbf{10}$$$.</p><p>A string $$$a$$$ is said to be a subsequence of string $$$b$$$ if $$$a$$$ can be obtained from $$$b$$$ by deleting some characters without changing the ordering of the remaining characters.</p><p>To perform a clockwise rotation on a sequence $$$c$$$ of size $$$k$$$ is to perform an operation which sets $$$c_1:=c_k, c_2:=c_1, c_3:=c_2, \ldots, c_k:=c_{k-1}$$$ simultaneously.</p><p>Determine the minimum number of operations Naman has to perform to convert $$$s$$$ into $$$t$$$ or say that it is impossible. </p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$n$$$ $$$(1 \le n \le 10^6)$$$ — the length of the strings.</p><p>The second line contains the binary string $$$s$$$ of length $$$n$$$.</p><p>The third line contains the binary string $$$t$$$ of length $$$n$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>If it is impossible to convert $$$s$$$ to $$$t$$$ after any number of operations, print $$$-1$$$.</p><p>Otherwise, print the minimum number of operations required.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004925207729778338" id="id007302957179880606" class="input-output-copier">Copy</div></div><pre id="id004925207729778338">6
010000
000001
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009316957246197242" id="id007094924601556761" class="input-output-copier">Copy</div></div><pre id="id009316957246197242">1</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007417895451492347" id="id009045971972214262" class="input-output-copier">Copy</div></div><pre id="id007417895451492347">10
1111100000
0000011111
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id003908408420173607" id="id0026388320456986125" class="input-output-copier">Copy</div></div><pre id="id003908408420173607">5</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0022771059916888325" id="id00677377718282602" class="input-output-copier">Copy</div></div><pre id="id0022771059916888325">8
10101010
01010101
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005905496606547765" id="id005561158213218474" class="input-output-copier">Copy</div></div><pre id="id005905496606547765">1</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id003275112067066792" id="id006490942525123647" class="input-output-copier">Copy</div></div><pre id="id003275112067066792">10
1111100000
1111100001
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009429181579594268" id="id0003393867929091521" class="input-output-copier">Copy</div></div><pre id="id009429181579594268">-1</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test, Naman can choose the subsequence corresponding to indices $$$\{2, 6\}$$$ and rotate it once to convert $$$s$$$ into $$$t$$$.</p><p>In the second test, he can rotate the subsequence corresponding to all indices $$$5$$$ times. It can be proved, that it is the minimum required number of operations.</p><p>In the last test, it is impossible to convert $$$s$$$ into $$$t$$$.</p></div>