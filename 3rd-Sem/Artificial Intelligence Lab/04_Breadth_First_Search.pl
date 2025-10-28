% --- Facts: Graph edges ---
edge(a, b).
edge(a, c).
edge(b, d).
edge(b, e).
edge(c, f).
edge(c, g).
% --- BFS driver ---
bfs(Start, Goal, Path) :-
bfs_search([[Start]], Goal, RevPath),
reverse(RevPath, Path).
% --- BFS search loop ---
bfs_search([[Goal|RestPath] | _], Goal, [Goal|RestPath]). % Goal found
bfs_search([[Node|RestPath] | OtherPaths], Goal, Path) :-
findall([Next,Node|RestPath],
(edge(Node, Next), \+ member(Next, [Node|RestPath])),
NewPaths),
append(OtherPaths, NewPaths, UpdatedQueue),
bfs_search(UpdatedQueue, Goal, Path).
