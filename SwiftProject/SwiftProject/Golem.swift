//
//  Golem.swift
//  SwiftProject
//
//  Created by 周哲輝 on 2019/05/05.
//  Copyright © 2019 周哲輝. All rights reserved.
//

import Foundation

public struct Golem {
    var hp = 300
    var defense = 80
    var attack = 50
    
    init() {
        
    }
    
    init(hp: Int, defense: Int, attack: Int) {
        self.hp = hp
        self.defense = defense
        self.attack = attack
    }
}