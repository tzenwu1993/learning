#!/usr/bin/python
# -*- coding=UTF-8 -*-
import numpy as np
import matplotlib.pyplot as plt
plt.switch_backend('agg')
'''
后台需要GUI图形界面:FltkAgg, GTK, GTKAgg, GTKCairo, TkAgg , Wx or WxAgg
后台不需要GUI图形界面:Agg, Cairo, PS, PDF or SVG
'''

'''
input : 当前支持两列数据
    data  list列表 L=[[],[]]  可扩展对应数据列表
    title 标题
    output 输出文件名
'''
def plot_draw(data,title,output):
    xmin=min(data[0])-1
    xmax=max(data[0])+1
    ymin=min(data[1])-1 
    ymax=max(data[1])+1
    title="compare"
    x = data[0]
    y = data[1]
    plt.title(title)
    plt.ylabel("y label")
    plt.xlabel("x label")
    #plt.plot(x, y,'r--', x , z ,'bs')
    #设置其中的点的形状和颜色
    plt.plot(x, y,'r^')
    plt.axis([xmin,xmax,ymin,ymax])
    #plt.show()
    #plt.savefig('test.png', format='png')
    plt.savefig(output , format='png')


def test():
    L=[[1,2,3],[4,5,6]]
    plot_draw(L,"compare","test.png")


if __name__ == "__main__":
     test()

