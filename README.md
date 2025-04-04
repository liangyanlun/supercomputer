# supercomputer
写在前面

做这次招新题目对我来说有很大的收获。我以前很少接触过这种C/C++的项目，包括参加算法竞赛也只是对于单个题目写的单个程序，因此我也很珍惜这次机会，但可惜限于时间原因（准备比赛、体测、期中考试以及各种事情）没有好好地将程序完整地优化，只是在招新题期限的最开始两天和最后的几天进行了优化。但我感觉这次机会也很好地锻炼了我，让我对于超算比赛有了更好的认识。如果能够进队，我会以更加认真的态度进行学习训练；如果没有进队，这也将是我一份宝贵的经历。


开始


-2.登录超算节点 一开始并不知道怎么登陆，把密钥生成完毕之后就放在了一个犄角旮旯里，后向管理员@tkrdsk3一番请教终于登录上了，再次感谢 


-1.用不了perf 在历经多次尝试后发现wsl的Linux使用的并不是官网发行的linux内核，perf不能直接安装，需要使用非官方的perf工具。我在室友的帮助下，在github上找到了适配wsl的perf，下载后又经历千辛万苦才让perf编译成功。 


0.运用火焰图。下载编译运行火焰图的程序。这个过程还算快，没用多长时间就能用上火焰图。


1.发现sgemn速度缓慢，决定对矩阵乘法加速 

1.1使用多线程对程序加速。

通过看网上的教程学会了一些openmp的知识，也了解了多线程和锁的相关概念。在代码中，我所使用的多线程大多是对于for循环的加速。

相对于原程序，速度提升了 约2倍。

我本来认为for循环的多线程优化会有很大的加速，然而事实并不如我所料。把使用的线程数调大也没有明显的效果。我也一直在找原因，但能力有限没有找到。


1.2使用SIMD加速

SIMD也是在学习了一些相关知识后才了解。我使用了AVX2对矩阵乘法进行了优化。

相对于改进前，速度提升了 约4倍。

这也是我没有想到的。因为我用的算法减少了约8倍运算次数。本来还想用perf看一看程序的速度瓶颈在哪里，结果由于现在还没有查明的原因perf损坏了。在重新下载编译perf的过程中，又出现了第一次安装时没有的问题，而且是源码中的error。直到现在我还没有用上perf。（可恶的微软魔改内核什么都不兼容）


2.对其他部分的改进

在改进其他部分时，同样使用了多线程对for循环进行了优化。结果收效甚微，还没有来得及看是什么问题。

同时，我认为也可以用多线程对filter_transform和image_transform进行同时计算，这可能会有一些效果，不过还没有来得及完成。

另外，在transform的过程中，还有大量的乘加运算。我认为这也可以用SIMD进行优化。同样也是没有时间完成。

结语

可能还是想法太多，码力欠缺，有的想法还没有实现。

再次感谢大家的帮助。
