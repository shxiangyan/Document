XMU_master_and_doctor_degree_thesis
===================================

# encoding: UTF-8

用的字体：

英文：

    serif:  Times New Roman PS Std
    sans-serif: Mosquito Formal Std
    monospace: Lucida Sans Typewriter Std
        
中文：

    宋体：Adobe Song Std
    黑体：Adobe Heiti Std
    楷体：Adobe Kaiti Std
        
可从我的[网盘下载](http://pan.baidu.com/s/1qYIixtU)

Linux下将解压出的OTF目录放到/usr/share/fonts下，或~/.fonts下，运行
    
    fc-cache
    
即可。

Windows下把字体文件拖到 c:\WINDOWS\Fonts下，安装即可。

文件作用：

main.tex 是模板的正文，

author.tex是作者的信息，

abstracts目录下放的是中英文摘要，

chapters下放的是各章节及发表的论文和致谢，

figrues目录下放的是图形，

config目录下是模板的设置文件，

reference目录下放的是BibTeX的文献数据库，

a3cover目录下放的是生成A3封面的tex文件，

submmit_abstracts目录下放的是生成论文提交时用的单页中英文摘要。

使用步骤：

1. 确保系统中安装的几个opentype字体，当然可以自己选用其他字体，字体的设置在 config/headinfo.tex中，有中英文两部分。

2. 在author.tex中写入你的个人信息；

3.  在chapters目录下更新或增加需要的章节、发表的文章、致谢等；在写的同时在reference.bib中添加相应的参考文献信息。

4. 生成pdf文件：    

		xelatex -no-pdf -quiet -time-statistics main.tex
		
		bibtex main.aux
		
		xelatex -no-pdf -quiet -time-statistics main.tex
		
		xelatex -quiet -time-statistics main.tex
    
