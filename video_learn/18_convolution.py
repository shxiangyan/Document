import numpy as np
import cv2
import tensorflow as tf
import matplotlib.pyplot as plt


dataset=cv2.imread('/home/yan/Pictures/Scrot/2020-02-26-234611_1057x716_scrot.png',cv2.IMREAD_COLOR)

img=cv2.imread('/home/yan/Pictures/Scrot/2020-02-29-212742_301x317_scrot.png',cv2.IMREAD_COLOR)

dataset=np.array([dataset])
print(dataset.shape)
banch,height,width,channels=dataset.shape#1张,高,宽,通道

#plt.imshow(dataset)
#plt.show()

#print(img.shape,img2.shape)
#cv2.imshow('image',img)#第一个参数是窗口名字,第二个参数是图片变量

# 加载数据集
# 输入图片通常是3D，[height, width, channels]
# mini-batch通常是4D，[mini-batch size, height, width, channels]
#dataset = np.array(load_sample_images().images, dtype=np.float32)
# 数据集里面两张图片，一个中国庙宇，一个花
#batch_size, height, width, channels = dataset.shape

#dataset=np.array(img,dtype=np.float32)
#dataset2=np.array(img2,dtype=np.float32)
#dataset=np.array([dataset,dataset2])#第一张图与第二张图大小不同所以不能直接合并

# 创建两个filter
# 高，宽，通道，卷积核
# 7, 7, channels, 2个,注意:卷积核是图在前,个数在后,图是相反.卷积核的通道数与特征图的通道数相同,但是卷积核的个数可以与通道数不同
filters_test = np.zeros(shape=(7, 7, channels, 2), dtype=np.float32)
#创建两个filter卷积核
filters_test[:, 3, :, 0] = 1  # 垂直,所有行的第三列
filters_test[:,4,:,0]=1
filters_test[:,2,:,0]=1
filters_test[3, :, :, 1] = 1  # 水平,所有通道所有列的第三行

# filter参数是一个filters的集合
X = tf.placeholder(tf.float32, shape=(None, height, width, channels))# strides=[1, 2, 2, 1] 中第一最后一个为1规定，中间对应sh和sw,左右和上下移动的步长

convolution = tf.nn.conv2d(X, filter=filters_test, strides=[1, 2, 2, 1], padding='SAME')




with tf.Session() as sess:
    output = sess.run(convolution, feed_dict={X: dataset})


#plt.imshow(dataset[0])    
#plt.imshow(output[0, :, :, 1])  # 绘制第一个图的第二个特征图,默认三通道图,plt.imshow(img[:,:,2],plt.cm.gray)灰度图
#plt.show()

#plt.figure(num='astronaut',figsize=(8,8))  #创建一个名为astronaut的窗口,并设置大小

plt.subplot(2,2,1)     #将窗口分为两行两列四个子图，则可显示四幅图片
plt.title('origin image')   #第一幅图片标题
plt.imshow(dataset[0])      #绘制第一幅图片

plt.subplot(2,2,2)     #第二个子图
plt.title('R channel')   #第二幅图片标题
plt.imshow(output[0,:,:,0],plt.cm.gray)      #绘制第二幅图片,且为灰度图,第一张图片的第一张特征图
plt.axis('off')     #不显示坐标尺寸

plt.subplot(2,2,3)     #第三个子图
plt.title('G channel')   #第三幅图片标题
plt.imshow(output[0,:,:,1],plt.cm.gray)      #绘制第三幅图片,且为灰度图,第一张图片的第二张特征图
plt.axis('off')     #不显示坐标尺寸

plt.subplot(2,2,4)     #第四个子图
plt.title('B channel')   #第四幅图片标题
plt.imshow(img,plt.cm.gray)      #绘制第四幅图片,且为灰度图
plt.axis('off')     #不显示坐标尺寸

plt.show()   #显示窗口
