# CUI-graph

## 説明
Linuxのターミナル上で動作するグラフ描画ツールです。
グラフの線の太さが一定で、見やすく描画されます。

## 対応端末
- コマンドプロンプトを搭載している端末

## 導入方法
1. `gcc`が導入されていない場合はインストール

2. 以下のコマンドでコンパイル
```bash
gcc -o graph graph.c -lm
```

3. 実行
```bash
./graph
```
## 描画する関数を変更する場合
描画する関数を変更する場合はプログラムを直接書き換えてください。
