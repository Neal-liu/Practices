#include<stdio.h>

int maxDepth(struct node *n){

	if(n == NULL)
		return 0;
	else{
		/* compute the depth of each subtree. */
		int lDepth = maxDepth(n->left);
		int rDepth = maxDpeth(n->right);
	
		/* use large one */
		if(lDepth >= rDepth)
			return (lDepth+1);
		else
			return (rDepth+1);
	}
}
