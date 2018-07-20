# 算法竞赛入门经典--个人摘录笔记

## 程序真实运行时间的计算
使用以下代码可以计算得到以秒为单位的运行时间。
<pre><code>clock() / CLOCKS_PER_SEC</code></pre>  

## 输入输出框架  
输入结束后scanf函数将无法再次读取，将会返回0。因此可使用类似以下的写法：  
<pre><code>while(scanf("%d", &x) == 1)</code></pre>  
  
### 利用文件进行数据输入输出：  
1. 使用输入输出重定向。  
<pre><code>freopen("input.txt", "r", stdin)</code></pre>  
<pre><code>freopen("output.txt", "w", stdout)</code></pre>  
以上语句将使scanf从input.txt中读入，printf写入output.txt。  
  
2. 直接使用文件IO（不允许使用重定向的场合）  

### 读取带空格和回车的不确定长度字符串：  
利用fgets(fin)从文件fin中读取一个（下一个）字符，返回的是整数，需要手动类型转换，最后一个读出的是EOF  
利用getchar读取标准输入的下一个字符  

## 数组与字符串  

### 常量数组（适用于替换非常多case的switch->找对应关系）  

### 判断字符“是否为字母”，利用isaplha函数  
头文件ctype.h中的实用函数：  
1. isalpha：是否为字母
2. isdigit：是否为数字
3. isprint：是否为可打印字符（非控制字符）
4. toupper、tolower：转换大小写  

### 

