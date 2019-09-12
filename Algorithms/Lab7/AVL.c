#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//typedef int int;

#define LEFT 0
#define RIGHT 1
#define NEITHER -1
typedef int direction;

typedef struct node_s {
   int        value;
   struct node_s *next[2];
   int longer:2;
} *node;
#define Balanced(n) (n->longer < 0)

node avl_find(node tree, int target)
{
	while (tree && target != tree->value) {
		direction next_step = (target > tree->value);
		tree = tree->next[next_step];
	}
	return tree;
}



void avl_rebalance_path(node path, int target)
{
	/* Each node in path is currently balanced.
	 * Until we find target, mark each node as longer
	 * in the direction of target because we know we have
	 * inserted target there
	 */
	while (path && target != path->value) {
		direction next_step = (target > path->value);
		path->longer = next_step;
		path = path->next[next_step];
	}
}

node avl_rotate_2(node *path_top, direction dir)
{
	node B, C, D, E;
	B = *path_top;
	D = B->next[dir];
	C = D->next[1-dir];
	E = D->next[dir];
	*path_top = D;
	D->next[1-dir] = B;
	B->next[dir] = C;
	B->longer = NEITHER;
	D->longer = NEITHER;
	return E;
}


node avl_rotate_3(node *path_top, direction dir, direction third)
{
	node B, F, D, C, E;
	B = *path_top;
	F = B->next[dir];
	D = F->next[1-dir];
	/* node: C and E can be NULL */
	C = D->next[1-dir];
	E = D->next[dir];
	*path_top = D;
	D->next[1-dir] = B;
	D->next[dir] = F;
	B->next[dir] = C;
	F->next[1-dir] = E;
	D->longer = NEITHER;

	/* assume both trees are balanced */
	B->longer = F->longer = NEITHER;

	if (third == NEITHER)
		return NULL;

	if (third == dir) {
		/* E holds the insertion so B is unbalanced */ 
		B->longer = 1-dir;
		return E;
	} else {
		/* C holds the insertion so F is unbalanced */
		F->longer = dir;
		return C;
	}
}


void avl_rebalance(node *path_top, int target)
{
	node path = *path_top;
	direction first, second, third;
	if (Balanced(path)) {
		avl_rebalance_path(path, target);
		return;
	}
	first = (target > path->value);
	if (path->longer != first) {
		/* took the shorter path */
		path->longer = NEITHER;
		avl_rebalance_path(path->next[first], target);
		return;
	}
	/* took the longer path, need to rotate */
	second = (target > path->next[first]->value);
	if (first == second) {
		/* just a two-point rotate */
		path = avl_rotate_2(path_top, first);
		avl_rebalance_path(path, target);
		return;
	}
	/* fine details of the 3 point rotate depend on the third step.
	 * However there may not be a third step, if the third point of the
	 * rotation is the newly inserted point.  In that case we record
	 * the third step as NEITHER
	 */
	path = path->next[first]->next[second];
	if (target == path->value) third = NEITHER;
	else third = (target > path->value);
	path = avl_rotate_3(path_top, first, third);
	avl_rebalance_path(path, target);
}


int avl_insert(node *treep, int target)
{
	/* insert the target into the tree, returning 1 on success or 0 if it
	 * already existed
	 */
	node tree = *treep;
	node *path_top = treep;
	while (tree && target != tree->value) {
		direction next_step = (target > tree->value);
		if (!Balanced(tree)) path_top = treep;
		treep = &tree->next[next_step];
		tree = *treep;
	}
	if (tree) return 0;
	tree =(struct node_s*) malloc(sizeof(struct node_s));
	tree->next[0] = tree->next[1] = NULL;
	tree->longer = NEITHER;
	tree->value = target;
	*treep = tree;
	avl_rebalance(path_top, target);
	return 1;
}

void avl_print(node tree, int depth, direction side)
{
	if (tree) {
		avl_print(tree->next[LEFT], depth+1, LEFT);
		printf("%*s%c %d %c\n", depth*2, "", ":/\\"[side+1], tree->value, ":/\\"[tree->longer+1]);
		avl_print(tree->next[RIGHT], depth+1, RIGHT);
	}
}



int main(int argc, char *argv[])
{
	node tree = NULL;
	int arg;
	for (arg=1; arg<argc; arg++) {
		if (avl_insert(&tree, atoi(argv[arg])))
			printf("Inserted %d\n", atoi(argv[arg]));
		else
			printf("Duplicate: %d\n", atoi(argv[arg]));
	}
	avl_print(tree, 0, NEITHER);


	exit(0);
}

//http://www.martinbroadhurst.com/avl-tree-in-c.html
//https://neil.brown.name/blog/20041124101820