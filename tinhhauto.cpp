#include "trungto.cpp"
/*
ý tưởng:tính giá trị biểu thức hậu tố :253 6 7 3 + * 15 * +
+duyệt vòng lập for từ đầu chuỗi đến cuối 
+nếu gặp số thì đẩy vào stack
+nếu gặp + - * / thì pop ra 2 phần tử trong stack rồi thực hiện phép toán sau đó đẩy kết quả của phép toán quay lại stack
chạy tay:253 6 7 3 + * 15 * +
+gặp lần lượt  253,6,7,3=>stack =253 6 7 3
+gặp +=> đẩy 7 và 3 ra thực hiện 7+3=10,đẩy 10 lại stack=253 6 10
+gặp *=> đẩu 6 và 10 ra thực hiện 6*10=60 đẩy 60 lại stack =253 60 
+gặp 15=>stack =253 60 15
+gặp *=> đẩy 15 và 60 ra thực hiện 15*60=900 đẩy 900 lại stack =253 900
+gặp +=> đẩy 253 và 900 ra thực hiện 900+253=1153 đẩy lại stack =1153
khi kết thúc vòng lập stack chỉ còn lại duy nhất 1 giá trị và đó là kết quả phép toán
*/
int tinhhauto(STACK &stack, string so)
{
    int n = so.size();
    for (int i = 0; i < n; i++)
    {
        char temp[20];
        int idx = 0;
        while (so[i] >= '0' && so[i] <= '9')
        {
            temp[idx++] = so[i];//là số thì bắt đầu đẩy vào mảng temp 
            i++;
        }
        if (idx != 0) //đã vào thực hiện vòng while
        {
            temp[idx] = '\0';//cho =\0 để báo hiểu kết thúc chuỗi và ép nó về string
            string tmp(temp);
            i--; //lùi lại 1 giá trị do tăng ở trong while
            stack.push(tmp);
        }
        if(so[i]=='+'||so[i]=='-'||so[i]=='*'||so[i]=='/')
        {
            int kq;
            int so2=stoi(stack.pop());//biến nó về số để tính toán
            int so1=stoi(stack.pop());
            if(so[i]=='+')
            {
                kq=so1+so2;
            }
            else if (so[i]=='-')
            {
                kq=so1-so2;
            }
            else if (so[i]=='*')
            {
                kq=so1*so2;
            }
            else
            {
                kq=so1/so2;
            }
            string tam=to_string(kq);//biến kiểu int sang string để đẩy ngược vể stack
            stack.push(tam);
        }
    }
    string ketqua=stack.pop();
    return stoi(ketqua);
}
int main()
{
    STACK stack;
    string sohauto = trungtosanghauto(stack, "253+6*(7+3)*15");
    int giatribieuthuc = tinhhauto(stack, sohauto);
    cout<<giatribieuthuc<<endl;
    return 0;
}