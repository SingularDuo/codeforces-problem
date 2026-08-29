<h2><a href="https://codeforces.com/contest/1486/problem/B" target="_blank" rel="noopener noreferrer">1486B — Eastern Exhibition</a></h2>

| | |
|---|---|
| **Difficulty** | 1500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1486B](https://codeforces.com/contest/1486/problem/B) |

## Topics
`binary search` `geometry` `shortest paths` `sortings`

---

## Problem Statement

<div class="header"><div class="title">B. Eastern Exhibition</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You and your friends live in $$$n$$$ houses. Each house is located on a 2D plane, in a point with integer coordinates. There might be different houses located in the same point. The mayor of the city is asking you for places for the building of the Eastern exhibition. You have to find the number of places (points with integer coordinates), so that the summary distance from all the houses to the exhibition is minimal. The exhibition can be built in the same point as some house. The distance between two points $$$(x_1, y_1)$$$ and $$$(x_2, y_2)$$$ is $$$|x_1 - x_2| + |y_1 - y_2|$$$, where $$$|x|$$$ is the absolute value of $$$x$$$. </p></div><div class="input-specification"><div class="section-title">Input</div><p>First line contains a single integer $$$t$$$ $$$(1 \leq t \leq 1000)$$$ — the number of test cases.</p><p>The first line of each test case contains a single integer $$$n$$$ $$$(1 \leq n \leq 1000)$$$. Next $$$n$$$ lines describe the positions of the houses $$$(x_i, y_i)$$$ $$$(0 \leq x_i, y_i \leq 10^9)$$$.</p><p>It's guaranteed that the sum of all $$$n$$$ does not exceed $$$1000$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case output a single integer - the number of different positions for the exhibition. The exhibition can be built in the same point as some house.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0045856992745718617" id="id0021707850249808847" class="input-output-copier">Copy</div></div><pre id="id0045856992745718617">6
3
0 0
2 0
1 2
4
1 0
0 2
2 3
3 1
4
0 0
0 1
1 0
1 1
2
0 0
1 1
2
0 0
2 0
2
0 0
0 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00647881314370531" id="id0002977688509334042" class="input-output-copier">Copy</div></div><pre id="id00647881314370531">1
4
4
4
3
1
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>Here are the images for the example test cases. Blue dots stand for the houses, green — possible positions for the exhibition.</p><p><img class="tex-graphics" src="https://espresso.codeforces.com/52c5cab9f62c36a39afff83e6173fc39454a609f.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>First test case.</p><p><img class="tex-graphics" src="https://espresso.codeforces.com/d8a4ed875c6aaaa0842cddaf5244802e85ac0016.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>Second test case. <img class="tex-graphics" src="https://espresso.codeforces.com/ec963ca3f5cdec14c16bdadbdfe5de7e745038e0.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>Third test case. <img class="tex-graphics" src="https://espresso.codeforces.com/a7060f5901f14722064f89afac2c2281b3f33f14.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>Fourth test case. <img class="tex-graphics" src="https://espresso.codeforces.com/cdca5ecf5a1646128762e90e8597da5c54831e08.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>Fifth test case. <img class="tex-graphics" src="https://espresso.codeforces.com/169fd734967e7516d10fd64d89bdf6b2a314a9ff.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>Sixth test case. Here both houses are located at $$$(0, 0)$$$.</p></div>