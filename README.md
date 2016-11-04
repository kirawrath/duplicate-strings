# duplicate-strings

	How this algorithm works:

	Instead of using the brute-force approach of saving every new unique set,
	and then on each insertion compare the set being inserted with every previous set,
	I have elaborated a way to insert it at the same time I compare against the previous sets,
	using a n-tree structure. Obviously the first thing I do is to sort my input in ascending order.

	I think it is easier to explain with an example:
	Suppose I have the following input:

	1,2,3,4
	3,5,7
	1,2,7

	You can notice that the third line has a starting substring in common with the first line,
	so why not just add to my structure the difference between the two sets?
	This is what I'm doing with this tree:

			root
			 /\
			1  3
		   /    \
		  2      5
		 / \      \
		3   7      7
	   /
	  4

	There is always only one path to follow for every new string added, and it will either
	stop before adding new nodes, or it will create new nodes as needed. Every possible path
	is a unique string/set (I also count the unique substrings when I get one).

	Every node has an attribute "visited", which counts how many times that node was the last node
	of a set/string. This is necessary to count how many duplicates of a string I've already processed.
	For example, after the above input, suppose I have a input like this:

	1,2
	1,2
	1,2

	Walking on the above tree, you will notice that I never reach a leaf node by adding just the
	set "1,2", but everytime I reach the node '2', I increment that counter so I know that I got
	duplicates there.

# Complexity

	For memory complexity, it is easy to see that it depends on the input. If my input
	has plenty of duplicate sets, or if there are many sets that start with the same numbers,
	I will only need a few nodes to represent the whole input, but if every set starts with a 
	different number, then I will have to save every number of the input, so the complexity is the
	in the order of the size of the input O(n) in the worst case scenario.

	Now, for the time complexity, one can easily notice that this structure will perform much better
	in average than its brute-force counterpart, however it is possible to make a worst-case
	scenario where my algorithm will perform just the same as the brute-force approach.

	Example:

	1
	2
	3
	3,4
	3,4,5
	3,4,6
	3,4,7
	3,4,7,8
	3,4,7,8,9
	3,4,7,8,10

	And so on. In this example, every new insertion has to read every node in the tree.

	The above input's tree would be something like this:

			1-root
			   /\
			  2  3
				 |
				 4-5
				 /\
				6  7
				   |
				   8
				  /\
				 9  10

	Because every node would have many edges, and I have to look at each child node to choose one,
	I would end up reading every node (and thus every number in the input) to keep adding new
	numbers in that sequence (of course if I my input stop to follow this pattern, my algorithm
	will start to improve its performance).

	Therefore, in this (unlikely) worst case scenario, we would have the following number of comparisons
	(for each line in the input, I'm writing the number of comparisons at its side).

	1           (0)
	2           (1)
	3           (2)
	3,4         (3)
	3,4,5       (3+1)=4
	3,4,6       (3+1+1)=5
	3,4,7       (3+1+2)=6
	3,4,7,8     (3+1+3)=7
	3,4,7,8,9   (3+1+3+1)=8
	3,4,7,8,10  (3+1+3+2)=9

	We all know that 1+2+3+...+n = n^2, so that's our complexity, O(n^2).

# How to improve the solution
	Note that the performance gets deteriorated when the nodes have too many edges, but also note
	that every child node is ordered, so when you are searching for a child to go down the tree,
	you can apply a binary search algorithm to find your child node faster.

	Analizying the complexity with this improvement, we would get something like:
	log2(1)+log2(2)+...+log2(n), which is log(n!)/log(2). I suggest you to plot this to see
	that it is not that bad.
