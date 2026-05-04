** Hệ thống Quản lý Chuyến bay và Đặt vé (Flight Management System)**
Một chương trình Console Application được viết bằng ngôn ngữ C/C++, ứng dụng cấu trúc dữ liệu Danh sách liên kết đơn (Singly Linked List) để quản lý thông tin các chuyến bay và quá trình đặt/hủy vé của hành khách.

Dự án này là một ví dụ trực quan về cách áp dụng Cấu trúc dữ liệu & Giải thuật vào bài toán quản lý thực tế, kết hợp với các thao tác xử lý File I/O.

🚀 Các tính năng chính
Chương trình hoạt động thông qua một Menu tương tác trên Terminal với các chức năng:

Thêm chuyến bay mới (addFlight): Nhập thông tin chuyến bay bao gồm Mã chuyến, Tên máy bay, Điểm đi/đến, Số lượng ghế (VIP/Thường), Ngày và Giờ khởi hành.

Hiển thị danh sách chuyến bay (displayFlights): In ra bảng thống kê chi tiết các chuyến bay hiện có trong hệ thống và tình trạng ghế trống.

Đặt vé máy bay (bookTicket):

Hỗ trợ chọn hạng vé (VIP hoặc Thường).

Tự động sinh mã ghế (Seat Label) thông minh: Ví dụ A1, B2 cho ghế VIP và a1, b2 cho ghế thường.

Tự động cập nhật số lượng ghế đã đặt trên chuyến bay tương ứng.

Hủy vé (cancelTicket): Tìm kiếm theo ID vé, xóa khỏi hệ thống và tự động hoàn trả lại số lượng ghế trống cho chuyến bay.

Hiển thị danh sách vé đã đặt (displayTickets): In ra bảng chi tiết thông tin hành khách, ghế ngồi và thông tin hành trình.

Lưu trữ dữ liệu vĩnh viễn (loadData & saveData): Tự động tải dữ liệu từ file khi khởi động và lưu toàn bộ thay đổi xuống file text trước khi thoát chương trình.

🛠 Kiến trúc & Kỹ thuật sử dụng
Ngôn ngữ: C (Có thể biên dịch bằng trình biên dịch C hoặc C++)

Cấu trúc dữ liệu: * Struct: Quản lý các thực thể phức tạp như Flight (Chuyến bay), Ticket (Vé), DATE, HOUR.

Linked List: Sử dụng hai danh sách liên kết đơn độc lập với con trỏ headFlight và headTicket để quản lý bộ nhớ động linh hoạt (thêm/xóa Node).

Quản lý bộ nhớ: Cấp phát động với malloc() và giải phóng bộ nhớ với free().

Lưu trữ File: Thao tác đọc/ghi file tuần tự (Sequential File I/O) với plane.txt và ticket.txt.

📁 Cấu trúc file dữ liệu
Khi chương trình chạy, nó sẽ tự động tạo/đọc hai file văn bản trong cùng thư mục:

plane.txt: Lưu trữ danh sách chuyến bay (Mã, Tên, Số ghế, Lịch trình...). Định dạng phân tách bằng dấu |.

ticket.txt: Lưu trữ danh sách vé đã đặt (Mã vé, Hạng, Thông tin hành khách, ID CMND/CCCD...). Định dạng phân tách bằng dấu |.

💻 Hướng dẫn cài đặt và sử dụng
Yêu cầu hệ thống
Trình biên dịch C/C++ (GCC, MinGW, hoặc các IDE như Dev-C++, Code::Blocks, Visual Studio).

Cách chạy chương trình
Clone hoặc tải mã nguồn về máy.

Mở terminal/command prompt tại thư mục chứa file mã nguồn.

Biên dịch chương trình:

Bash
gcc Untitled1.cpp -o FlightSystem
# hoặc g++ nếu bạn dùng trình biên dịch C++
g++ Untitled1.cpp -o FlightSystem
Khởi chạy:

Trên Windows: FlightSystem.exe

Trên Linux/macOS: ./FlightSystem

Lưu ý: Nếu chương trình báo lỗi không tìm thấy file plane.txt hoặc ticket.txt ở lần chạy đầu tiên, đừng lo lắng. Hãy cứ thêm chuyến bay, đặt vé và ấn 0 để thoát, chương trình sẽ tự động tạo file cho bạn.

👥 Phân công công việc
Nếu sử dụng dự án này cho bài tập lớn nhóm, đây là cấu trúc module có thể chia để báo cáo:

Nguyễn Thành Đạt: Thiết kế cấu trúc dữ liệu (Struct, Node) và xử lý phần đọc/ghi File (loadData, saveData), thêm logic(thuật toán sinh mã ghế tự động).

Thành viên 2: Xây dựng logic Quản lý chuyến bay (Thêm, Xóa, Tìm kiếm, Hiển thị danh sách chuyến bay / vé) và thiết kế Menu chính.

Thành viên 3: Xây dựng logic Quản lý đặt vé (không cho đật vé: máy bay đã hết chỗ, máy bay không tồn tại).

Thành viên 4: Cập nhật chuyến bay và vé (chỗ ngồi, điểm đến và đi của máy bay).
