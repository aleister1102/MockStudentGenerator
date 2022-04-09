# Mock Students Generator Project
Đồ án ứng dụng việc tạo các lớp đơn giản và sinh số ngẫu nhiên.

# Thời gian thực hiện
01/04/2022 - 09/04/2022 (Hoàn thành yêu cầu đề ra)
10/04/2022 - ??/??/2022 (Cập nhật - tối ưu, nếu có)

# Chi tiết đồ án
Chương trình chạy theo luồng như sau:
- Đọc tất cả các học sinh từ file "students.txt" vào vector (tạm gọi là S).
- Random một số `n`.
- Random `n` học sinh và cho vào vector S.
- Ghi đè lại file "students.txt" bằng vector S mới.
- In ra GPA trung bình của các học sinh.
- In ra tất cả các học sinh có GPA trên mức trung bình.

Trong đồ án sử dụng nhiều thư viện tích hợp của C++: vector, sstream, fstream, regex.

Các class được chia thành hai loại:
1. Business Class gồm các class để xử lý như Random, String, File, Converter.
2. DTO Class bao gồm các class chứa dữ liệu: Student, FullName, Address, etc.

Dữ liệu lấy từ các nguồn có sẵn, có ghi trong slide môn học.

## Quy tắc commit
- feat: thêm tính năng mới
- fix: update hoặc sửa code
- chore: làm mấy thứ lặt vặt bên ngoài như đổi tên file, sửa data, ...
- refactor: làm gọn code nhưng ko ảnh hưởng đến logic của code

## Cấu trúc thư mục
- data: dữ liệu
- include: các file header
- build: file .o và .exe

## Ngôn ngữ sử dụng: C/C++.
## Công cụ hỗ trợ: 
VScode, Visual Studio, Git/Github.

# Về chúng tôi
- 20120356: Lê Minh Quân
- 20120386: Lê Phước Toàn

# Tham khảo

- Choose first name from this [list](https://vi.wikipedia.org/wiki/H%E1%BB%8D_ng%C6%B0%E1%BB%9Di_Vi%E1%BB%87t_Nam).
- Choose middle name from this [list](http://www.erct.com/4-ChiaSe/SuuTam/Tinh_danh-TEN_DEM.htm).
- Choose last name from this [list](https://xltiengviet.fandom.com/wiki/T%C3%AAn_ng%C6%B0%E1%BB%9Di_Vi%E1%BB%87t_Nam).
