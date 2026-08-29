<h2><a href="https://codeforces.com/contest/1225/problem/F" target="_blank" rel="noopener noreferrer">1225F — Tree Factory</a></h2>

| | |
|---|---|
| **Difficulty** | 2500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1225F](https://codeforces.com/contest/1225/problem/F) |

## Topics
`constructive algorithms` `greedy` `trees`

---

## Problem Statement

<div class="header"><div class="title">F. Tree Factory</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Bytelandian Tree Factory produces trees for all kinds of industrial applications. You have been tasked with optimizing the production of a certain type of tree for an especially large and important order.</p><p>The tree in question is a rooted tree with $$$n$$$ vertices labelled with distinct integers from $$$0$$$ to $$$n - 1$$$. The vertex labelled $$$0$$$ is the root of the tree, and for any non-root vertex $$$v$$$ the label of its parent $$$p(v)$$$ is less than the label of $$$v$$$.</p><p>All trees at the factory are made from bamboo blanks. A <span class="tex-font-style-it">bamboo</span> is a rooted tree such that each vertex has exactly one child, except for a single leaf vertex with no children. The vertices of a bamboo blank can be labelled arbitrarily before its processing is started.</p><p>To process a bamboo into another tree a single type of operation can be made: choose an arbitrary non-root vertex $$$v$$$ such that its parent $$$p(v)$$$ is not a root either. The operation consists of changing the parent of $$$v$$$ to its parent's parent $$$p(p(v))$$$. Note that parents of all other vertices remain unchanged, in particular, the subtree of $$$v$$$ does not change.</p><p>Efficiency is crucial, hence you have to minimize the number of operations to make the desired tree from a bamboo blank. Construct any optimal sequence of operations to produce the desired tree.</p><p>Note that the labelling of the resulting tree has to coincide with the labelling of the desired tree. Formally, the labels of the roots have to be equal, and for non-root vertices with the same label the labels of their parents should be the same.</p><p>It is guaranteed that for any test present in this problem an answer exists, and further, an optimal sequence contains at most $$$10^6$$$ operations. Note that <span class="tex-font-style-bf">any hack that does not meet these conditions will be invalid</span>.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$n$$$ — the number of vertices in the tree ($$$2 \leq n \leq 10^5$$$).</p><p>The second line contains $$$n - 1$$$ integers $$$p(1), \ldots, p(n - 1)$$$ — indices of parent vertices of $$$1, \ldots, n - 1$$$ respectively ($$$0 \leq p(i)  \lt  i$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>In the first line, print $$$n$$$ distinct integers $$$id_1, \ldots, id_n$$$ — the initial labelling of the bamboo blank starting from the root vertex ($$$0 \leq id_i  \lt  n$$$).</p><p>In the second line, print a single integer $$$k$$$ — the number of operations in your sequence ($$$0 \leq k \leq 10^6$$$).</p><p>In the third line print $$$k$$$ integers $$$v_1, \ldots, v_k$$$ describing operations in order. The $$$i$$$-th operation consists of changing $$$p(v_i)$$$ to $$$p(p(v_i))$$$. Each operation should be valid, i.e. neither $$$v_i$$$ nor $$$p(v_i)$$$ can be the root of the tree at the moment.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id003767274932329917" id="id0006718966459228126" class="input-output-copier">Copy</div></div><pre id="id003767274932329917">5
0 0 1 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005795130899328198" id="id007543781710429531" class="input-output-copier">Copy</div></div><pre id="id005795130899328198">0 2 1 4 3
2
1 3
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005315297247250507" id="id00018288939649513503" class="input-output-copier">Copy</div></div><pre id="id005315297247250507">4
0 1 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009875854915952411" id="id0021426473137991642" class="input-output-copier">Copy</div></div><pre id="id009875854915952411">0 1 2 3
0

</pre></div></div></div>