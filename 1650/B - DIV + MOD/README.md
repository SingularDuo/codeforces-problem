<h2><a href="https://codeforces.com/contest/1650/problem/B" target="_blank" rel="noopener noreferrer">1650B — DIV + MOD</a></h2>

| | |
|---|---|
| **Difficulty** | 900 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1650B](https://codeforces.com/contest/1650/problem/B) |

## Topics
`math`

---

## Problem Statement

<div class="header"><div class="title">B. DIV + MOD</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Not so long ago, Vlad came up with an interesting function:</p><ul><li> $$$f_a(x)=\left\lfloor\frac{x}{a}\right\rfloor + x \bmod a$$$, where $$$\left\lfloor\frac{x}{a}\right\rfloor$$$ is $$$\frac{x}{a}$$$, rounded <span class="tex-font-style-bf">down</span>, $$$x \bmod a$$$ — the remainder of the integer division of $$$x$$$ by $$$a$$$.</li></ul><p>For example, with $$$a=3$$$ and $$$x=11$$$, the value $$$f_3(11) = \left\lfloor\frac{11}{3}\right\rfloor + 11 \bmod 3 = 3 + 2 = 5$$$.</p><p>The number $$$a$$$ is fixed and known to Vlad. Help Vlad find the maximum value of $$$f_a(x)$$$ if $$$x$$$ can take any integer value from $$$l$$$ to $$$r$$$ inclusive ($$$l \le x \le r$$$).</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of input data contains an integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of input test cases.</p><p>This is followed by $$$t$$$ lines, each of which contains three integers $$$l_i$$$, $$$r_i$$$ and $$$a_i$$$ ($$$1 \le l_i \le r_i \le 10^9, 1 \le a_i \le 10^9$$$) — the left and right boundaries of the segment and the fixed value of $$$a$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output one number on a separate line — the maximum value of the function on a given segment for a given $$$a$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0026427685544343205" id="id007474153419593941" class="input-output-copier">Copy</div></div><pre id="id0026427685544343205"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">1 4 3</div><div class="test-example-line test-example-line-even test-example-line-2">5 8 4</div><div class="test-example-line test-example-line-odd test-example-line-3">6 10 6</div><div class="test-example-line test-example-line-even test-example-line-4">1 1000000000 1000000000</div><div class="test-example-line test-example-line-odd test-example-line-5">10 12 8</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0004985516422508329" id="id006173576925048373" class="input-output-copier">Copy</div></div><pre id="id0004985516422508329">2
4
5
999999999
5
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample:</p><ul> <li> $$$f_3(1) = \left\lfloor\frac{1}{3}\right\rfloor + 1 \bmod 3 = 0 + 1 = 1$$$, </li><li> $$$f_3(2) = \left\lfloor\frac{2}{3}\right\rfloor + 2 \bmod 3 = 0 + 2 = 2$$$, </li><li> $$$f_3(3) = \left\lfloor\frac{3}{3}\right\rfloor + 3 \bmod 3 = 1 + 0 = 1$$$, </li><li> $$$f_3(4) = \left\lfloor\frac{4}{3}\right\rfloor + 4 \bmod 3 = 1 + 1 = 2$$$ </li></ul><p>As an answer, obviously, $$$f_3(2)$$$ and $$$f_3(4)$$$ are suitable.</p></div>