//
//  main.swift
//  SwiftProject
//
//  Created by 周哲輝 on 2019/05/05.
//  Copyright © 2019 周哲輝. All rights reserved.
//

import Foundation

func ShowSelections(chapter: Int) {
    for i in 1...4 {
        print("\t\(i)) K0\(chapter)_\(i)")
    }
}

var executables = [IExecutable]()
executables.append(K01())
executables.append(K02())
executables.append(K03())
executables.append(K04())
executables.append(K05())
executables.append(K06())

print("実行したいプログラムを選択してください。")

for i in 1...6 {
    print("\(i)) K0\(i)")
}

if let choice = Int(readLine()!) {
    ShowSelections(chapter: choice)
    let choice2 = Int(readLine()!)
    executables[choice - 1].Execute(num: choice2!)
}