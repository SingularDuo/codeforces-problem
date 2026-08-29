<h2><a href="https://codeforces.com/contest/1715/problem/E" target="_blank" rel="noopener noreferrer">1715E — Long Way Home</a></h2>

| | |
|---|---|
| **Difficulty** | 2400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1715E](https://codeforces.com/contest/1715/problem/E) |

## Topics
`data structures` `divide and conquer` `dp` `geometry` `graphs` `greedy` `shortest paths`

---

## Problem Statement

<div class="header"><div class="title">E. Long Way Home</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Stanley lives in a country that consists of $$$n$$$ cities (he lives in city $$$1$$$). There are bidirectional roads between some of the cities, and you know how long it takes to ride through each of them. Additionally, there is a flight between each pair of cities, the flight between cities $$$u$$$ and $$$v$$$ takes $$$(u - v)^2$$$ time.</p><p>Stanley is quite afraid of flying because of watching "Sully: Miracle on the Hudson" recently, so he can take at most $$$k$$$ flights. Stanley wants to know the minimum time of a journey to each of the $$$n$$$ cities from the city $$$1$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>In the first line of input there are three integers $$$n$$$, $$$m$$$, and $$$k$$$ ($$$2 \leq n \leq 10^{5}$$$, $$$1 \leq m \leq 10^{5}$$$, $$$1 \leq k \leq 20$$$) — the number of cities, the number of roads, and the maximal number of flights Stanley can take.</p><p>The following $$$m$$$ lines describe the roads. Each contains three integers $$$u$$$, $$$v$$$, $$$w$$$ ($$$1 \leq u, v \leq n$$$, $$$u \neq v$$$, $$$1 \leq w \leq 10^{9}$$$) — the cities the road connects and the time it takes to ride through. Note that some pairs of cities may be connected by more than one road.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print $$$n$$$ integers, $$$i$$$-th of which is equal to the minimum time of traveling to city $$$i$$$.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006463815026713925" id="id009327727062815261" class="input-output-copier">Copy</div></div><pre id="id006463815026713925">3 1 2
1 3 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0036690671280471177" id="id008328531196821782" class="input-output-copier">Copy</div></div><pre id="id0036690671280471177">0 1 1 </pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009272078478948572" id="id008748111903313293" class="input-output-copier">Copy</div></div><pre id="id009272078478948572">4 3 1
1 2 3
2 4 5
3 4 7
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id000273194620093139" id="id0005733477946811749" class="input-output-copier">Copy</div></div><pre id="id000273194620093139">0 1 4 6 </pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007866033497313658" id="id006897553898629558" class="input-output-copier">Copy</div></div><pre id="id007866033497313658">2 1 1
2 1 893746473
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008756328277825738" id="id008533827203774104" class="input-output-copier">Copy</div></div><pre id="id008756328277825738">0 1 </pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0025751046762828333" id="id0032012537072296754" class="input-output-copier">Copy</div></div><pre id="id0025751046762828333">5 5 2
2 1 33
1 5 93
5 3 48
2 3 21
4 2 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009282819782721669" id="id00361327887525309" class="input-output-copier">Copy</div></div><pre id="id009282819782721669">0 1 2 2 3 </pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample, it takes no time to get to city 1; to get to city 2 it is possible to use a flight between 1 and 2, which will take 1 unit of time; to city 3 you can get via a road from city 1, which will take 1 unit of time. </p><p>In the second sample, it also takes no time to get to city 1. To get to city 2 Stanley should use a flight between 1 and 2, which will take 1 unit of time. To get to city 3 Stanley can ride between cities 1 and 2, which will take 3 units of time, and then use a flight between 2 and 3. To get to city 4 Stanley should use a flight between 1 and 2, then take a ride from 2 to 4, which will take 5 units of time.</p></div>