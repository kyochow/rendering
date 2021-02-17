#  10个旋转的Cube

## DrawCall 到底是什么

本质上，就是glDrawArrays(xxx);或glDrawElements(xxx)方法的调用
本例子中，本例子，共10次drawcall

## 如何减少drawcall？

batch 合并批次，将多次glDrawArrays调用合并成一次

unity中包括静态合批和动态合批
这样整个理论就完整了
