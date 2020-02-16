# FusionDesignProject
授業の融合デザインプロジェクトの共同開発用リポジトリ

# 環境構築
**環境変数に注意すること。**

## Kinect for Windows SDK 2.0
[ここ](https://developer.microsoft.com/ja-jp/windows/kinect/)のサイトから`Kinect for Windows SDK 2.0`をダウンロード、インストール。

## OpenCV
たぶん3.4.8。vc14とvc15はvc15を選んだ。
[これ](https://qiita.com/laviee/items/d2a035959b7a8acfa9c0)を見れば大体できると思う。



## Visual Studio

Kinect SDKインストール後、そのままKinectApp内のslnファイルを実行できなかったら、[こちら](https://qiita.com/imura/items/101b37a2d85cc30b1e35#visual-studio-の準備)を参考に、追加のインクルードディレクトリ、追加のライブラリディレクトリ、追加の依存ファイルを追加する。

# 各ディレクトリについて

## Python
pythonで作った各種スクリプト
### udp_recieve_test.py
受け取ったUDPを標準出力に表示するだけ。特にエラー処理していないから、運が悪いと止まる。
### udp_send_test.py
ローカルにUDPで"Hello"を0.2秒間隔で送り続ける

## TempuraRun

ゲーム本体