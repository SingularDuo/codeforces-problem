<h2><a href="https://codeforces.com/contest/1185/problem/F" target="_blank" rel="noopener noreferrer">1185F — Two Pizzas</a></h2>

| | |
|---|---|
| **Difficulty** | 2100 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1185F](https://codeforces.com/contest/1185/problem/F) |

## Topics
`bitmasks` `brute force`

---

## Problem Statement

<div class="header"><div class="title">F. Two Pizzas</div><div class="time-limit"><div class="property-title">time limit per test</div>4 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>A company of $$$n$$$ friends wants to order exactly two pizzas. It is known that in total there are $$$9$$$ pizza ingredients in nature, which are denoted by integers from $$$1$$$ to $$$9$$$.</p><p>Each of the $$$n$$$ friends has one or more favorite ingredients: the $$$i$$$-th of friends has the number of favorite ingredients equal to $$$f_i$$$ ($$$1 \le f_i \le 9$$$) and your favorite ingredients form the sequence $$$b_{i1}, b_{i2}, \dots, b_{if_i}$$$ ($$$1 \le b_{it} \le 9$$$).</p><p>The website of CodePizza restaurant has exactly $$$m$$$ ($$$m \ge 2$$$) pizzas. Each pizza is characterized by a set of $$$r_j$$$ ingredients $$$a_{j1}, a_{j2}, \dots, a_{jr_j}$$$ ($$$1 \le r_j \le 9$$$, $$$1 \le a_{jt} \le 9$$$) , which are included in it, and its price is $$$c_j$$$.</p><p>Help your friends choose exactly two pizzas in such a way as to please the maximum number of people in the company. It is known that a person is pleased with the choice if <span class="tex-font-style-bf">each</span> of his/her favorite ingredients is in at least one ordered pizza. If there are several ways to choose two pizzas so as to please the maximum number of friends, then choose the one that minimizes the total price of two pizzas.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input contains two integers $$$n$$$ and $$$m$$$ ($$$1 \le n \le 10^5, 2 \le m \le 10^5$$$) — the number of friends in the company and the number of pizzas, respectively.</p><p>Next, the $$$n$$$ lines contain descriptions of favorite ingredients of the friends: the $$$i$$$-th of them contains the number of favorite ingredients $$$f_i$$$ ($$$1 \le f_i \le 9$$$) and a sequence of distinct integers $$$b_{i1}, b_{i2}, \dots, b_{if_i}$$$ ($$$1 \le b_{it} \le 9$$$).</p><p>Next, the $$$m$$$ lines contain pizza descriptions: the $$$j$$$-th of them contains the integer price of the pizza $$$c_j$$$ ($$$1 \le c_j \le 10^9$$$), the number of ingredients $$$r_j$$$ ($$$1 \le r_j \le 9$$$) and the ingredients themselves as a sequence of distinct integers $$$a_{j1}, a_{j2}, \dots, a_{jr_j}$$$ ($$$1 \le a_{jt} \le 9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output two integers $$$j_1$$$ and $$$j_2$$$ ($$$1 \le j_1,j_2 \le m$$$, $$$j_1 \ne j_2$$$) denoting the indices of two pizzas in the required set. If there are several solutions, output any of them. Pizza indices can be printed in any order.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00916261166798577" id="id00607082210186207" class="input-output-copier">Copy</div></div><pre id="id00916261166798577">3 4
2 6 7
4 2 3 9 5
3 2 3 9
100 1 7
400 3 3 2 5
100 2 9 2
500 3 2 9 5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009369088564074944" id="id005188865279362798" class="input-output-copier">Copy</div></div><pre id="id009369088564074944">2 3
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007266878061463954" id="id005125878279520603" class="input-output-copier">Copy</div></div><pre id="id007266878061463954">4 3
1 1
1 2
1 3
1 4
10 4 1 2 3 4
20 4 1 2 3 4
30 4 1 2 3 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006165496599144326" id="id005163254322547077" class="input-output-copier">Copy</div></div><pre id="id006165496599144326">1 2
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005505229376100802" id="id003742757298322644" class="input-output-copier">Copy</div></div><pre id="id005505229376100802">1 5
9 9 8 7 6 5 4 3 2 1
3 4 1 2 3 4
1 4 5 6 7 8
4 4 1 3 5 7
1 4 2 4 6 8
5 4 1 9 2 8
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00956107694633984" id="id0028615757895923566" class="input-output-copier">Copy</div></div><pre id="id00956107694633984">2 4
</pre></div></div></div>