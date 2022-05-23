## Hướng dẫn cài đặt:
- Người chơi bấm nút bắt đầu,chọn map và xử dụng các nút điều hướng để chơi.
## Mô tả chung về trò chơi, các ý tưởng chính
-Người chơi vượt qua các map mê cung để có thể tìm đc đến vạch  đích.
- Ý tưởng chính: Là thiết kế map bằng kỹ thuật tile map, sau đó check va chạm của nhân vật với các ô gạch.
## Các kỹ thuật lập trình được sử dụng trong chương trình
- COn trỏ.
- Class (Lớp button, lớp Timer, lớp BaseObject, lớp Music,...).
- Kỹ thuật Tile_map (lưu trữ thông tin map dưới dạng .txt).
- Đọc xuất file.
### Thông tin về code và tài nguyên
- Em học SDL2 từ kênh [phát triển phần mềm 123az](https://phattrienphanmem123az.com/) và web [Lazyfoo](https://lazyfoo.net/tutorials/SDL/index.php), em tham khảo lớp BaseObject và lớp Timer.
- Em tự viết toàn bộ code, tự triển khai _logic game_.
- Phần tài nguyên hình ảnh thì em lấy ở trang pngtree âm thanh em lấy nhạc trên youtube.
### Những điều đã đạt được sau khi code
- Em đã khá thành thạo với thư viện SDL2, với lập trình hướng đối tượng, sử dụng các class.
- Logic game đã xét hết mọi khả năng nhận đầu vào từ người dùng.
- Trò chơi có nhiều tính năng hay như chọn map, hay nhiều nút tính năng như Pause Game, Pause Music,PLay Music, Play Game,Previous Level,Hiển thị level hiện tại,.
### Một số nhược điểm và hướng phát triển
- Thêm BXH và có thể bấm nút chơi lại khi trò chơi kết thúc
- Em sẽ nâng cấp thêm các đồng xu trên đường đi để tính điểm nhân vật 
- Em sẽ điều chỉnh thêm FPS để nhân vật đi mượt hơn
- Em sẽ thêm một vài vật cản không cho nhân vật đi qua 
