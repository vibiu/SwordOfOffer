
PROG = run
CC = g++
CPPFLAGS = -g -Wall

SOURCES = main.cpp 
# ALGORITHM = AssignmentOperator.cpp
# ALGORITHM = Singleton.cpp
# ALGORITHM = FindDuplication.cpp
# ALGORITHM = FindInPartiallySortedMatrix.cpp
# ALGORITHM = ReplaceSpaces.cpp
# ALGORITHM = PrintListInReversedOrder.cpp
# ALGORITHM = ConstructBinaryTree.cpp
# ALGORITHM = NextNodeInBinaryTrees.cpp
# ALGORITHM = QueueWithTwoStacks.cpp
# ALGORITHM = Fibonacci.cpp
# ALGORITHM = MinNumberInRotatedArray.cpp
# ALGORITHM = StringPathInMatrix.cpp
# ALGORITHM = RobotMove.cpp
# ALGORITHM = CuttingRope.cpp
# ALGORITHM = NumberOf1InBinary.cpp
# ALGORITHM = Power.cpp
# ALGORITHM = Print1ToMaxOfNDigits.cpp
# ALGORITHM = DeleteNodeInList.cpp
# ALGORITHM = DeleteDuplicatedNode.cpp
# ALGORITHM = RegularExpressions.cpp
# ALGORITHM = NumericStrings.cpp
# ALGORITHM = ReorderArray.cpp
# ALGORITHM = KthNodeFromEnd.cpp
# ALGORITHM = EntryNodeInListLoop.cpp
# ALGORITHM = ReverseList.cpp
# ALGORITHM = MergeSortedLists.cpp
# ALGORITHM = SubstructrueInTree.cpp
# ALGORITHM = MirrorOfBinaryTree.cpp
# ALGORITHM = SymmetricalBinaryTree.cpp
# ALGORITHM = PrintMatrix.cpp
# ALGORITHM = MinInStack.cpp
# ALGORITHM = StackPushPopOrder.cpp
# ALGORITHM = PrintTreeFromTopToBottom.cpp
# ALGORITHM = PrintTreesInLines.cpp
# ALGORITHM = PrintTreesInZigzag.cpp
# ALGORITHM = SquenceOfBST.cpp
# ALGORITHM = PathInTree.cpp
# ALGORITHM = CopyComplexList.cpp
# ALGORITHM = ConvertBinarySearchTree.cpp
# ALGORITHM = SerializeBinaryTrees.cpp
# ALGORITHM = StringPermutaion.cpp
# ALGORITHM = MoreThanHalfNumber.cpp
# ALGORITHM = KLeastNumbers.cpp
# ALGORITHM = StreamMedian.cpp
# ALGORITHM = GreatestSumOfSubarrays.cpp
# ALGORITHM = NumberOf1.cpp
# ALGORITHM = DigitsInSequence.cpp
# ALGORITHM = SortArrayForMinNumber.cpp
# ALGORITHM = TranslateNumbersToStrings.cpp
# ALGORITHM = MaxValueOfGifts.cpp
# ALGORITHM = LongestSubstringWithoutDup.cpp
# ALGORITHM = UglyNumber.cpp
# ALGORITHM = FirstNotRepeatingChar.cpp
# ALGORITHM = FirstCharacterInStream.cpp
# ALGORITHM = InversePairs.cpp
# ALGORITHM = FirstCommonNodesInLists.cpp
# ALGORITHM = NumberOfK.cpp
# ALGORITHM = MissingNumber.cpp
# ALGORITHM = IntegerIdenticalToIndex.cpp
# ALGORITHM = KthNodeInBST.cpp
# ALGORITHM = TreeDepth.cpp
# ALGORITHM = BalancedBinaryTree.cpp
# ALGORITHM = NumbersAppearOnce.cpp
# ALGORITHM = NumberAppearingOnce.cpp
# ALGORITHM = TwoNumbersWithSum.cpp
# ALGORITHM = ContinuousSquenceWithSum.cpp
# ALGORITHM = ReverseWordsInSentence.cpp
# ALGORITHM = LeftRotateString.cpp
# ALGORITHM = MaxInSlidingWindow.cpp
# ALGORITHM = QueueWithMax.cpp
# ALGORITHM = DicesProbability.cpp
# ALGORITHM = ContinousCard.cpp
# ALGORITHM = LastNumberInCircle.cpp
# ALGORITHM = MaximalProfit.cpp
# ALGORITHM = Accumulate.cpp
# ALGORITHM = AddTwoNumbers.cpp
# ALGORITHM = ConstructArray.cpp
# ALGORITHM = StringToInt.cpp
ALGORITHM = CommonParentInTree.cpp


UTIL = ./utils/
UTILS = ${UTIL}List.cpp ${UTIL}BinaryTree.cpp ${UTIL}ComplexList.cpp \
	${UTIL}Array.cpp ${UTIL}StringUtil.cpp ${UTIL}Tree.cpp

.PHONY: ${PROG}

$(PROG): ${SOURCES} ${UTILS}
	${CC} -o ${PROG} ${SOURCES} ${UTILS} ${ALGORITHM}
