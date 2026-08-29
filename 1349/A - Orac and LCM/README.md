<h2><a href="https://codeforces.com/contest/1349/problem/A" target="_blank" rel="noopener noreferrer">1349A — Orac and LCM</a></h2>

| | |
|---|---|
| **Difficulty** | 1600 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1349A](https://codeforces.com/contest/1349/problem/A) |

## Topics
`data structures` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">A. Orac and LCM</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>For the multiset of positive integers $$$s=\{s_1,s_2,\dots,s_k\}$$$, define the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of $$$s$$$ as follow:</p><ul><li> $$$\gcd(s)$$$ is the maximum positive integer $$$x$$$, such that all integers in $$$s$$$ are divisible on $$$x$$$.</li><li> $$$\textrm{lcm}(s)$$$ is the minimum positive integer $$$x$$$, that divisible on all integers from $$$s$$$.</li></ul><p>For example, $$$\gcd(\{8,12\})=4,\gcd(\{12,18,6\})=6$$$ and $$$\textrm{lcm}(\{4,6\})=12$$$. Note that for any positive integer $$$x$$$, $$$\gcd(\{x\})=\textrm{lcm}(\{x\})=x$$$.</p><p>Orac has a sequence $$$a$$$ with length $$$n$$$. He come up with the multiset $$$t=\{\textrm{lcm}(\{a_i,a_j\})\ |\ i \lt j\}$$$, and asked you to find the value of $$$\gcd(t)$$$ for him. In other words, you need to calculate the GCD of LCMs of all pairs of elements in the given sequence.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$n\ (2\le n\le 100\,000)$$$.</p><p>The second line contains $$$n$$$ integers, $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \leq a_i \leq 200\,000$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print one integer: $$$\gcd(\{\textrm{lcm}(\{a_i,a_j\})\ |\ i \lt j\})$$$.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006849364223180551" id="id0018804216782275462" class="input-output-copier">Copy</div></div><pre id="id006849364223180551">2
1 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007271158740642901" id="id005528808677804964" class="input-output-copier">Copy</div></div><pre id="id007271158740642901">1
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009400365698161759" id="id00277451070690374" class="input-output-copier">Copy</div></div><pre id="id009400365698161759">4
10 24 40 80
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id000008147261095163838" id="id004516545694425643" class="input-output-copier">Copy</div></div><pre id="id000008147261095163838">40
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008766311206684116" id="id00529403224655991" class="input-output-copier">Copy</div></div><pre id="id008766311206684116">10
540 648 810 648 720 540 594 864 972 648
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00008138724732348668" id="id0035257277324213054" class="input-output-copier">Copy</div></div><pre id="id00008138724732348668">54
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>For the first example, $$$t=\{\textrm{lcm}(\{1,1\})\}=\{1\}$$$, so $$$\gcd(t)=1$$$.</p><p>For the second example, $$$t=\{120,40,80,120,240,80\}$$$, and it's not hard to see that $$$\gcd(t)=40$$$.</p></div>