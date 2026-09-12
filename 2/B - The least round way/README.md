<h2><a href="https://codeforces.com/contest/2/problem/B" target="_blank" rel="noopener noreferrer">2B — The least round way</a></h2>

| | |
|---|---|
| **Difficulty** | 2000 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2B](https://codeforces.com/contest/2/problem/B) |

## Topics
`dp` `math`

---

## Problem Statement

<div class="header"><div class="title">B. The least round way</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>64 megabytes</div><div class="input-file input-standard" style="font-weight: bold"><div class="property-title">input</div>stdin</div><div class="output-file output-standard" style="font-weight: bold"><div class="property-title">output</div>stdout</div></div><div><p>There is a square matrix <span class="tex-span"><i>n</i> × <i>n</i></span>, consisting of non-negative integer numbers. You should find such a way on it that </p><ul> <li> starts in the upper left cell of the matrix; </li><li> each following cell is to the right or down from the current cell; </li><li> the way ends in the bottom right cell. </li></ul><p>Moreover, if we multiply together all the numbers along the way, the result should be the least "round". In other words, it should end in the least possible number of zeros.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains an integer number <span class="tex-span"><i>n</i></span> (<span class="tex-span">2 ≤ <i>n</i> ≤ 1000</span>), <span class="tex-span"><i>n</i></span> is the size of the matrix. Then follow <span class="tex-span"><i>n</i></span> lines containing the matrix elements (non-negative integer numbers not exceeding <span class="tex-span">10<sup class="upper-index">9</sup></span>).</p></div><div class="output-specification"><div class="section-title">Output</div><p>In the first line print the least number of trailing zeros. In the second line print the correspondent way itself.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009079987275957291" id="id009471781751013565" class="input-output-copier">Copy</div></div><pre id="id009079987275957291">3<br>1 2 3<br>4 5 6<br>7 8 9<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006487517209173925" id="id008607813473906999" class="input-output-copier">Copy</div></div><pre id="id006487517209173925">0<br>DDRR<br></pre></div></div></div>