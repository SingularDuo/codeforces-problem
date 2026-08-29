<h2><a href="https://codeforces.com/contest/1195/problem/C" target="_blank" rel="noopener noreferrer">1195C — Basketball Exercise</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++20 (GCC 13-64) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1195C](https://codeforces.com/contest/1195/problem/C) |

## Topics
`dp`

---

## Problem Statement

<div class="header"><div class="title">C. Basketball Exercise</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Finally, a basketball court has been opened in SIS, so Demid has decided to hold a basketball exercise session. $$$2 \cdot n$$$ students have come to Demid's exercise session, and he lined up them into two rows of the same size (there are exactly $$$n$$$ people in each row). Students are numbered from $$$1$$$ to $$$n$$$ in each row in order from left to right.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/d86d754d6d2d8028a5014de45c1921110ba0b6dd.png" style="zoom: 75.0%;max-width: 100.0%;max-height: 100.0%;"> </center><p>Now Demid wants to choose a team to play basketball. He will choose players from left to right, and the index of each chosen player (excluding the first one <span class="tex-font-style-bf">taken</span>) will be strictly greater than the index of the previously chosen player. To avoid giving preference to one of the rows, Demid chooses students in such a way that no consecutive chosen students belong to the same row. The first student can be chosen among all $$$2n$$$ students (there are no additional constraints), and a team can consist of any number of students. </p><p>Demid thinks, that in order to compose a perfect team, he should choose students in such a way, that the total height of all chosen students is maximum possible. Help Demid to find the maximum possible total height of players in a team he can choose.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input contains a single integer $$$n$$$ ($$$1 \le n \le 10^5$$$) — the number of students in each row.</p><p>The second line of the input contains $$$n$$$ integers $$$h_{1, 1}, h_{1, 2}, \ldots, h_{1, n}$$$ ($$$1 \le h_{1, i} \le 10^9$$$), where $$$h_{1, i}$$$ is the height of the $$$i$$$-th student in the first row.</p><p>The third line of the input contains $$$n$$$ integers $$$h_{2, 1}, h_{2, 2}, \ldots, h_{2, n}$$$ ($$$1 \le h_{2, i} \le 10^9$$$), where $$$h_{2, i}$$$ is the height of the $$$i$$$-th student in the second row.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print a single integer — the maximum possible total height of players in a team Demid can choose.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0001874789884984651" id="id0041183987350638074" class="input-output-copier">Copy</div></div><pre id="id0001874789884984651">5
9 3 5 7 3
5 8 1 4 5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id002298710264784365" id="id005133305138687682" class="input-output-copier">Copy</div></div><pre id="id002298710264784365">29
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0034032314582679957" id="id0025446028854579206" class="input-output-copier">Copy</div></div><pre id="id0034032314582679957">3
1 2 9
10 1 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0045938411984534566" id="id00692119120888516" class="input-output-copier">Copy</div></div><pre id="id0045938411984534566">19
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005543417664202073" id="id00867403299946065" class="input-output-copier">Copy</div></div><pre id="id005543417664202073">1
7
4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0009708982706373337" id="id0002346558490307893" class="input-output-copier">Copy</div></div><pre id="id0009708982706373337">7
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example Demid can choose the following team as follows: </p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/4e91cbc6d188bea6a651a3ee663b4842b5a853d6.png" style="max-width: 100.0%;max-height: 100.0%;"> </center><p>In the second example Demid can choose the following team as follows: </p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/05e00446ce2bc15b43dee54633824f909a6e8695.png" style="max-width: 100.0%;max-height: 100.0%;"> </center></div>