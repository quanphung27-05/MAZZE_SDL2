## Hướng dẫn cài đặt:
- Người chơi thử nghiệm click vào [đây](https://drive.google.com/file/d/1fdsCyFFkO0IMCl60tb2mUySB-uU4owp7/view?usp=sharing) để tải file .zip về sau đó giải nén hoặc không. Sau đó mở file Mazze.exe để bắt đầu trải nghiệm trò chơi.
- Để bắt đầu trò chơi,người chơi phải bấm nút bắt đầu,chọn map và xử dụng các nút điều hướng lên, xuống, sang trái, sang phải để điều khiển nhân vật .
## Mô tả chung về trò chơi, các ý tưởng chính
- Người chơi vượt qua các map mê cung để có thể tìm được lối thoát ra ngoài.
- Ý tưởng chính:  Thiết kế map bằng kỹ thuật tile map, sau đó check va chạm của nhân vật với các ô gạch.
## Các chức năng đã cài đặt
- Có tùy chọn map yêu thích để chơi.
- Có cài đặt âm thanh để người chơi thư giãn khi chơi.
- Có chỗ hiển thị level hiện tại đang chơi.
- Có nút quay trở về level trước đó để chơi lại.
- Có nút menu hiện thị các tùy chọn như tắt âm thanh, về màn hình chính, tiếp tục trò chơi.
- Có thanh thời gian đếm ngược ngắn dần theo thời gian.
####  Nhấn vào [đây](https://youtu.be/Css1yAlwaUM) để xem video demo về Mazze Game
## Các kỹ thuật lập trình được sử dụng trong chương trình
- Con trỏ.
- Class (lớp ImpTimer, lớp BaseObject, lớp Music,...).
- Kỹ thuật Tile_map (lưu trữ thông tin map dưới dạng .txt).
- Đọc xuất file.
### Thông tin về code và tài nguyên
- Em học SDL2 từ kênh [phát triển phần mềm 123az](https://phattrienphanmem123az.com/) và web [Lazyfoo](https://lazyfoo.net/tutorials/SDL/index.php), em tham khảo lớp BaseObject và lớp ImpTimer.
- Em tự viết toàn bộ code ạ.
- Phần tài nguyên hình ảnh thì em lấy ở trang pngtree, âm thanh em lấy nhạc trên youtube.
### Những điều đã đạt được sau khi code
- Em đã khá thành thạo SDL2, sử dụng các class.
- Logic game không (ít) gây ra bug.
- Trò chơi có nhiều tính năng hay như chọn map, hay nhiều nút tính năng như Pause Game, Pause Music,PLay Music, Play Game,Previous Level,Hiển thị level hiện tại,.
### Một số nhược điểm và hướng phát triển
- Thêm BXH và có thể bấm nút chơi lại khi trò chơi kết thúc
- Em sẽ nâng cấp thêm các đồng xu trên đường đi để tính điểm nhân vật.
- Em sẽ điều chỉnh thêm FPS để nhân vật đi mượt hơn
- Em sẽ thêm một vài vật cản không cho nhân vật đi qua.
