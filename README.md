
#前言
***
&emsp;&emsp;&ensp;本文为**《数据结构与算法分析——c语言描述》**一书中核心代码的实现，博文将伴随着代码的提交持续进行更新，同时也真诚希望大家能对其中存在的问题提出建议与意见.

**[ 作者：]&emsp;andy**

**[ 联系方式：]&emsp;<angdychen@gmail.com>**

**[ 更新时间：]&emsp;2016年7月10日**
</br>
> ####&emsp;&emsp;If you want to become a good programmer, you can spend 10 years programming, or spend 2 years programming and learning algorithms.

***

#目录

1. [第一章 引言](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm)
	<br/>
2. [第二章 算法分析](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC2%E7%AB%A0%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90)
 
 	* [折半查找](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC2%E7%AB%A0%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/%E6%8A%98%E5%8D%8A%E6%9F%A5%E6%89%BE)
	* [数组主元](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC2%E7%AB%A0%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/%E6%95%B0%E7%BB%84%E4%B8%BB%E5%85%83)
	* [最大子序列和](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC2%E7%AB%A0%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%88%97%E5%92%8C)
	* [汉诺塔](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC2%E7%AB%A0%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/%E6%B1%89%E8%AF%BA%E5%A1%94)
	* [约瑟夫环](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC2%E7%AB%A0%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/%E7%BA%A6%E7%91%9F%E5%A4%AB%E7%8E%AF)
	* [裴波那契数列](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC2%E7%AB%A0%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/%E8%A3%B4%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97)
	</br>
3. [第三章 表ADT](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC3%E7%AB%A0%E8%A1%A8ADT)
	
	* [链表](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC3%E7%AB%A0%E8%A1%A8ADT/%E9%93%BE%E8%A1%A8)
	* [栈](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC3%E7%AB%A0%E8%A1%A8ADT/%E6%A0%88)
	* [队列](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC3%E7%AB%A0%E8%A1%A8ADT/%E9%98%9F%E5%88%97)
	* [多项式](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC3%E7%AB%A0%E8%A1%A8ADT/%E5%A4%9A%E9%A1%B9%E5%BC%8F)
	</br>
4. [第四章 树](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC4%E7%AB%A0%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%A0%91)
	* [二叉树](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC4%E7%AB%A0%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%A0%91)
		<font color=BurlyWood>
		1. 二叉树的创建
		2. 先序遍历（递归，非递归）
		3. 中序遍历（递归，非递归）
		4. 后序遍历（递归，非递归）
		5. 层次遍历
		6. 求二叉树深度
		7. 求二叉树宽度
		8. 求二叉树中结点个数
		9. 求二叉树第K层节点的个数
		1. 求二叉树中叶子节点的个数
		2. 判断两个二叉树是否相等（结构，对应元素都相同）
		
		</font>
	* [二叉查找树](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC4%E7%AB%A0%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%9F%A5%E6%89%BE%E6%A0%91)

5. [第七章 排序](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC7%E7%AB%A0%E6%8E%92%E5%BA%8F)
	1. [插入类排序](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC7%E7%AB%A0%E6%8E%92%E5%BA%8F/1.%E6%8F%92%E5%85%A5%E7%B1%BB%E6%8E%92%E5%BA%8F)
		* 直接插入排序
		* 希尔排序
	2. [选择类排序](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC7%E7%AB%A0%E6%8E%92%E5%BA%8F/2.%E9%80%89%E6%8B%A9%E7%B1%BB%E6%8E%92%E5%BA%8F)
	    * 简单选择排序
	    * 堆排序
	3. [交换类排序](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC7%E7%AB%A0%E6%8E%92%E5%BA%8F/3.%E4%BA%A4%E6%8D%A2%E7%B1%BB%E6%8E%92%E5%BA%8F)
		* 冒泡排序
		* 快速排序
	4. [归并类排序](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E7%AC%AC7%E7%AB%A0%E6%8E%92%E5%BA%8F/4.%E5%BD%92%E5%B9%B6%E7%B1%BB%E6%8E%92%E5%BA%8F)
		* 归并排序
	5. [基数类排序]()
		* 桶式排序
		* 基数排序
6. [补充: 串](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E4%B8%B2/KMP%E7%AE%97%E6%B3%95)
	1. [字符串匹配算法](https://github.com/angdychen/EverydayAlgorithm/tree/master/Algorithm/%E4%B8%B2/KMP%E7%AE%97%E6%B3%95)
		* BF朴素字符串匹配算法
		* KMP字符串匹配算法
		
		
