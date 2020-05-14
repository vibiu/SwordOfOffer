#if !defined(COMMON_PARENT_IN_TREE_H_)
#define COMMON_PARENT_IN_TREE_H_
#include "utils/Tree.h"
#include <list>
using std::list;

bool GetNodePath(const TreeNode *pRoot, const TreeNode *pNode, list<const TreeNode *> &path);

const TreeNode *GetLastCommonNode(const list<const TreeNode *> &path1, const list<const TreeNode *> &path2);

const TreeNode *GetLastCommonParent(const TreeNode *pRoot, const TreeNode *pNode1, const TreeNode *pNode2);

void CommonParentInTreeTest(const char *testName, const TreeNode *pRoot, const TreeNode *pNode1,
                             const TreeNode *pNode2, TreeNode *pExpected);

void CommonParentInTreeTest1();

#endif // COMMON_PARENT_IN_TREE_H_
