import socket
import time

HOST = ""
PORT = 5000
ADDRESS = "127.0.0.1"

class udp_loop():
    def __init__(self):
        try:
            self.s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        except socket.error as identifier:
            print(identifier)

    def send_udp_loop(self):
        # 一秒に五回送信
        while True:
            time.sleep(0.2)
            self.s.sendto("Hello".encode(), (ADDRESS, PORT))

    def close(self):
        self.s.close()

if __name__ == "__main__":
    looper = udp_loop()
    print("Push Ctrl-c to exit.")
    try:
        looper.send_udp_loop()
    except KeyboardInterrupt as e:
        looper.close()
        print("Finished to send.")