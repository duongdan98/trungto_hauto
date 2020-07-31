#include "ClassStack.cpp"
/*
ý tưởng:chuyển biểu thức trung tố sang hậu tố 253+6*(7+3)*15
+duyệt vòng lập qua tất cả các phần tử của chuỗi
+nếu gặp số đẩy vào mảng kết quả(tức là mảng hậu tố)
+nếu gặp + - * / thì đẩy vào stack 
+nếu thứ tự uư tiên của phần tử trên cùng của của stack lớn hơn hoặc bằng với phần tử đang xét
thì đẩy phần tử trên cùng của ngăn xếp ra mảng kết quả đến khi thứ tự ưu tiên của phần tử trên cùng 
không lớn hơn phần tử đang xét thì đấy phần tử đang xét vào stack 
+nếu gặp dấu ) "đóng ngoặc" thì pop hết các phần tử ra đến khi gặp dấu ( "mở ngoặc"
+khi đã kết thúc vòng lập (tức là duyệt hết chuỗi) mà stack vẫn còn phần tử thì đấy hết ra mảng kết quả
chạy tay:253+6*(7+3)*15
+gặp 253=> đẩy vào mảng kp=253;stack=rỗng
+gặp + => stack đang rỗng => đẩy vào stack=+
+gặp 6=>đẩy vào mảng kq=253 6
+gặp * stack đang không rỗng nhưng độ ưu tiên của * là 2 độ ưu tiên của + là 1 nên đẩy vào stack =+*
+gặp ( => đẩy vào stack=+*(
+gặp 7=>kq=253 6 7
+găp + stack đang không rỗng nhưng độ ưu tiên của + là 1 độ ưu tiên của ( là  nên đẩy vào stack =+*(+
+gặp 3=>kq=253 6 7 3 
+gặp )=>pop đến khi gặp dấu ("mở ngoặc" =>kq=253 6 7 3 +,stack= +*
+gặp * stack đang không rỗng nhưng độ ưu tiên của * là 2 độ ưu tiên của * là  bằng nhau nên pop * ra đẩy
vào mảng kp,pop đến + thì độ ưu tiên của + là 1 không lớn hơn hoặc bằng * nên dừng pop và đẩy * vào stack
kq=253 6 7 3 + *, stack =+*
+gặp 15=> kq=253 6 7 3 + * 15
+kết thúc chuỗi và stack vẫn còn nên ta pop hết ra đẩy sang mảng kết quả
=>kq=253 6 7 3 + * 15 * +
*/
string trungtosanghauto(STACK &stack, string so)
{
    char kq[50];
    int idx = 0;
    int n = so.size();
    for (int i = 0; i < n; i++)
    {
        if (so[i] == '(')//gặp ( đẩy vào stack
        {
            char temp[2] = {so[i], '\0'};//ép char vể mảng
            string s(temp);//ép mảng về string
            stack.push(s);
        }
        if (so[i] >= '0' && so[i] <= '9')
        {
            while (so[i] >= '0' && so[i] <= '9')
            {
                kq[idx++] = so[i];//gặp số là đẩy vào mảng kq cho đến khi khác số thì dừng 
                i++;
            }
            kq[idx++] = ' ';//thêm khoảng trắng cho kết quả dễ nhìn và chút nữa tính toán được biếu thức hậu tố
            i--;//vì mỗi lần cuối của while ta đã trót tăng lên i++ nên cần giảm i để tránh sót
        }
        if (so[i] == '+' || so[i] == '-' || so[i] == '*' || so[i] == '/')
        {
            if (stack.isEmpty() == 1)//stack rỗng đẩy vào stack
            {
                char temp[2] = {so[i], '\0'};
                string s(temp);
                stack.push(s);
            }
            else
            {
                while ((stack.isEmpty() == 0) && (uutien(so[i]) <= uutien(stack.Top())))
                { //nếu ngăn xếp không rỗng và độ ưu tiên của phần tử so[i]nhỏ hơn hoặc bằng phần
                    //tử trên cùng của ngăn thì lấy phần tử trên cùng ra bỏ ra kq
                    string temp = stack.pop();//pop trả về 1 string,tring này chắc chắn có 2 phần tử
                    kq[idx++] = temp[0];//và phần tử đầu chắc chắn là +-*/ và phần tử thứ 2 là '\0'
                    kq[idx++] = ' ';
                }
                //sau khi lấy hết phần tử ưu tiên lớn hơn ra thì mình thêm so[i] vào
                char temp[2] = {so[i], '\0'};
                string s(temp);
                stack.push(s);
            }
        }
        if (so[i] == ')')
		{//nếu gặp dấu đóng ngoặc thì lấy hết phần tử của ngăn ra đến khi gặp mở ngoặc
			string temp = stack.pop();
			while (temp[0] != '(')
			{
				kq[idx++] = temp[0];
				kq[idx++] = ' ';
				temp =stack.pop();
			}
		}
    }
    //nếu kết thúc vòng for trên tức là đã duyệt hết mảng mà ngăn xếp vẫn còn thì lấy hết ra cho vào kq
	while (stack.isEmpty()==0)
	{
		string k = stack.pop();
		kq[idx++] = k[0];
		kq[idx++] = ' ';
	}
    kq[--idx]='\0';
	string ketqua(kq);
	return ketqua;
}
int main()
{
    string s = "253+6*(7+3)*15";
    STACK stack;
  string ketqua=  trungtosanghauto(stack,s);
  cout<<ketqua<<endl;
  return 0;
}