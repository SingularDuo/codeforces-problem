<h2><a href="https://codeforces.com/contest/1359/problem/D" target="_blank" rel="noopener noreferrer">1359D — Yet Another Yet Another Task</a></h2>

| | |
|---|---|
| **Difficulty** | 2000 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1359D](https://codeforces.com/contest/1359/problem/D) |

## Topics
`data structures` `dp` `implementation` `two pointers`

---

## Problem Statement

<div class="header"><div class="title">D. Yet Another Yet Another Task</div><div class="time-limit"><div class="property-title">time limit per test</div>1.5 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Alice and Bob are playing yet another card game. This time the rules are the following. There are $$$n$$$ cards lying in a row in front of them. The $$$i$$$-th card has value $$$a_i$$$. </p><p>First, Alice chooses a non-empty consecutive segment of cards $$$[l; r]$$$ ($$$l \le r$$$). After that Bob removes a single card $$$j$$$ from that segment $$$(l \le j \le r)$$$. The score of the game is the total value of the remaining cards on the segment $$$(a_l + a_{l + 1} + \dots + a_{j - 1} + a_{j + 1} + \dots + a_{r - 1} + a_r)$$$. In particular, if Alice chooses a segment with just one element, then the score after Bob removes the only card is $$$0$$$.</p><p>Alice wants to make the score as big as possible. Bob takes such a card that the score is as small as possible.</p><p>What segment should Alice choose so that the score is maximum possible? Output the maximum score.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$n$$$ ($$$1 \le n \le 10^5$$$) — the number of cards.</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$-30 \le a_i \le 30$$$) — the values on the cards.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print a single integer — the final score of the game.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id003167292339857042" id="id008373489346233868" class="input-output-copier">Copy</div></div><pre id="id003167292339857042">5
5 -2 10 -1 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009314440555332242" id="id0012242446030901866" class="input-output-copier">Copy</div></div><pre id="id009314440555332242">6
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0014127990792432465" id="id006814646143378915" class="input-output-copier">Copy</div></div><pre id="id0014127990792432465">8
5 2 5 3 -30 -30 6 9
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0027493744932960196" id="id0007798290445825173" class="input-output-copier">Copy</div></div><pre id="id0027493744932960196">10
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0028512574536551505" id="id0019087170325207536" class="input-output-copier">Copy</div></div><pre id="id0028512574536551505">3
-10 6 -15
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009161767483729201" id="id005750762047511027" class="input-output-copier">Copy</div></div><pre id="id009161767483729201">0
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example Alice chooses a segment $$$[1;5]$$$ — the entire row of cards. Bob removes card $$$3$$$ with the value $$$10$$$ from the segment. Thus, the final score is $$$5 + (-2) + (-1) + 4 = 6$$$.</p><p>In the second example Alice chooses a segment $$$[1;4]$$$, so that Bob removes either card $$$1$$$ or $$$3$$$ with the value $$$5$$$, making the answer $$$5 + 2 + 3 = 10$$$.</p><p>In the third example Alice can choose any of the segments of length $$$1$$$: $$$[1;1]$$$, $$$[2;2]$$$ or $$$[3;3]$$$. Bob removes the only card, so the score is $$$0$$$. If Alice chooses some other segment then the answer will be less than $$$0$$$.</p></div>