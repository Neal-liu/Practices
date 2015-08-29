模擬面試練習題：

double.c : 

[links](https://hackpad.com/201498-3qQTDwVtzit#:h=Q3:-%E7%B5%A6%E5%AE%9A%E4%B8%80%E5%80%8B%E4%BB%8B%E6%96%BC-0-%E5%92%8C-1-%E4%B9%8B%E9%96%93%E7%9A%84%E5%AF%A6%E6%95%B8%EF%BC%8C%E5%A6%82-0.32%EF%BC%8C)

給定一個介於 0 和 1 之間的實數，如0.32，其型態為double，印出其二進位表示法。倘若無法精確用32位以內的二進位表示，則顯示 ERROR.


reverse.c : 

[links](https://stackoverflow.com/questions/1614723/why-is-this-string-reversal-c-code-causing-a-segmentation-fault)	
用 C 語言實做 void reverse(char *s) 來反轉 NULL 結尾的字串. 


rgba.c : 

[links](https://neal.hackpad.com/Summer-2015-Week-4-gcTpJvO9ZnC)

將 RGBA 轉換為黑白影像. 

請提出效能改善的方案：
- 建立表格加速浮點數操作 (L1 cache?)
- 減少位移數量
- 最終輸出的緩衝區 (in-place)
