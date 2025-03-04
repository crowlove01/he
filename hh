<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>文字选择游戏</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: rgb(0, 0, 0);
            color: #fefefe;
            text-align: center;
            padding: 50px;
        }
        #scene-title {
            font-size: 36px;
            margin-top: 20px;
        }

        #scene-description {
            font-size: 20px;
            margin-top: 10px;
        }
        .choice {
            margin: 10px;
            padding: 10px 20px;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        .choice:hover {
            background-color: #0056b3;
        }
        #end-screen {
            margin-top: 20px;
            font-size: 24px;
            color: #ff0000;
        }
    </style>
</head>
<body>
    <div id="game">
        <h1 id="scene-title">你收到了一封邀请函</h1>
        <p id="scene-description">你看到面前有一个穿着侍者服的鸟类玩偶，它用纽扣眼看着你，“名字？”</p>
        <button class="choice" onclick="choosePath(1)">告诉它</button>
        <button class="choice" onclick="choosePath(2)">不告诉它</button>
    </div>

    <script>
        const scenes = {
            start: {
                title: "你收到了一封邀请函",
                description: "你看到面前有一个穿着侍者服的鸟类玩偶，它用纽扣眼看着你，“名字？”",
                choices: [
                    { text: "告诉它", next: "tall" },
                    { text: "不告诉它", next: "nottall" }
                ]
            },
            tall: {
                title: "你说出来你的名字",
                description: "“苏禾，没错，您在贵宾名单上”玩偶推推眼镜，“请进”",
                choices: [
                    { text: "进入城堡", next: "enterCastle" },
                    { text: "绕过城堡", next: "bypassCastle" }
                ]
            },
            nottall: {
                title: "你不信任眼前这个怪东西，并没有告诉它你的名字",
                description: "“苏禾，你还是老样子”玩偶无语的看了你一眼“但你有邀请函还是请进吧”",
                choices: [
                    { text: "进入城堡", next: "enterCastle" },
                    { text: "绕过城堡", next: "bypassCastle" }
                ]
            },
            enterCastle: {
                title: "你进入了城堡",
                description: "城堡阴森恐怖，昏暗的烛光摇曳，带着发霉的腐臭味一阵阵冲进你的鼻腔，你哆嗦一下，刚想转头离开，却发现那个侍者已经关闭了大门",
                choices: [
                    { text: "四处探索", next: "lookaround" },
                    { text: "躲在原地", next: "stay" }
                ]
            },
            bypassCastle: {
                title: "你看着眼前阴森的城堡，决定绕过了城堡",
                description: "“呵呵，祝你好运”玩偶阴险的笑了一下，看着你渐渐远离，只是你刚踏出城堡，就被脚下的“藤蔓”绊倒，不对！这些“藤蔓”居然动起来了！他们把你层层包裹，你想要求救，却发现他们爬满了你的全身，你想要张嘴呼救，这些东西直接爬进了你的嘴里，被这些细细簌簌的东西包裹全身后你才意识到他们其实都是大大小小的蟑螂，但你已经再也发不出声音",
                isEnd: true, // 
                endMessage: "迷失", //
                choices: []
            },
            lookaround: {
                title: "你哆嗦着走过一段走廊",
                description: "走廊尽头是一扇虚掩的房门，露出来一点光和窸窸窣窣的低语声音",
                choices: [
                    { text: "打开门", next: "opendoor" },
                    { text: "在门口偷听", next: "eavesdrop" }
                ]
            },
            stay: {
                title: "你感觉你的脚因为害怕而难以移动",
                description: "突然，一阵阴风吹过，周围的烛火艰难的摇曳几下便完全熄灭了，四周陷入泼墨般的黑暗，害怕的你在黑暗中狂奔，但本应该撞到墙壁的距离却怎么都摸不到，四周仿佛什么都没有了，只剩下你和黑暗。",
                isEnd: true, // 
                endMessage: "迷失",
                choices: []
            },
            opendoor: {
                title: "你猛地打开门",
                description: "一瞬间，刚刚的低语声瞬间消失了，你环顾四周，发现这是间聚餐厅，餐桌上摆着美味的食物以及满满当当的宾客，他们转头看向你，你却发现看不起他们的脸，只有中间长着翅膀的女仆能看清脸。看到你来，他们一下子安静了，那个女仆恭敬的走了过来带你走到主坐上，女仆为你的面前摆上一份肉排和一杯红酒",
                choices: [
                    { text: "吃牛排", next: "eat" },
                    { text: "喝红酒", next: "drink" }
                ]
            },
            eavesdrop: {
                title: "你悄悄走到门口开始偷听",
                description: "“是的。。准。。好了。。等。。喝。。就立刻。。让她永。。”你心里一紧",
                choices: [
                    { text: "打开门", next: "opendoor1" }
                ]
            },
            opendoor1: {
                title: "你紧张的打开门",
                description: "低语声消失了，四周一片死寂，你看到巨大的餐桌上摆满食物，所有的宾客正齐齐看向你，一位长着翅膀的女仆恭敬的把你带到现在唯一空缺的主坐上，并为你摆上一杯腥红的红酒。",
                choices: [
                    { text: "喝红酒", next: "drink" },
                    { text: "掀翻桌子逃走", next: "run" }
                ]
            },
            eat: {
                title: "你缓缓地切开表面煎的娇嫩的牛肉",
                description: "里面流出猩红的液体，你咬牙吃下，一股铁锈的味道翻涌上来，你被恶心的狂呕，宾客们似乎被你的行为激怒，愤怒的放下手里的刀叉冲向你，你被所有人俺在地上，渐渐无力的放弃挣扎。",
                isEnd: true, // 
                endMessage: "迷失",
                choices: []
            },
            drink: {
                title: "你喝下红酒",
                description: "酒精的味道有点苦辣，你喝了一大口被呛到了，但你注意到所有人都在盯着你的动作，“嘭”小小的礼炮在这个大厅炸开，一瞬间大厅变得灯火通明，暖暖的火烛光芒照在每个人脸上，你逐渐看清他们的面庞，这些都是你的亲朋好友，他们脸上洋溢着祝福的微笑“生日快乐！苏禾！！”之前门口的侍者缓缓把一个七层蛋糕推过来，女仆把每层不同口味的蛋糕都切下一角放到你面前，你看着面前摇曳的生日蜡烛，留下动感的泪水",
                isEnd: true, // 
                endMessage: "你在你亲朋好友的祝福下度过愉快的2025，你很高兴，吃了很多美味的食物和谷子，相信你会度过开心快乐的一年",
                choices: []
            },
            run: {
                title: "你趁着所有人不注意，立刻掀翻你面前的餐食，然后快速向门跑去",
                description: "刚刚温驯的女仆此刻在你背后发出尖锐的嘶吼，你还没有跑到门口便被女仆按在门上，你感到你的脖子一阵刺痛，随机全身都失去了力气，渐渐滑倒。",
                isEnd: true, // 
                endMessage: "迷失",
                choices: []
            }
        };

        let currentScene = "start";

        function choosePath(choiceIndex) {
            const scene = scenes[currentScene];
            if (scene.choices.length > 0) {
                const nextSceneKey = scene.choices[choiceIndex - 1].next;
                currentScene = nextSceneKey;
                updateScene();
            }
        }

        function updateScene() {
            const scene = scenes[currentScene];
            const gameDiv = document.getElementById("game");

            // 判断是否为结局
            if (scene.isEnd) {
                gameDiv.innerHTML = `
                    <h1 id="scene-title">${scene.title}</h1>
                    <p id="scene-description">${scene.description}</p>
                    <div id="end-screen">
                        ${scene.endMessage} <!-- 显示独特结局信息 -->
                    </div>
                    <button class="choice" onclick="location.reload()">重新开始</button>
                `;
            } else {
                // 正常场景
                gameDiv.innerHTML = `
                    <h1 id="scene-title">${scene.title}</h1>
                    <p id="scene-description">${scene.description}</p>
                `;

                scene.choices.forEach((choice, index) => {
                    const button = document.createElement("button");
                    button.className = "choice";
                    button.innerText = choice.text;
                    button.onclick = () => choosePath(index + 1);
                    gameDiv.appendChild(button);
                });
            }
        }

        // 初始化游戏
        updateScene();
    </script>
</body>
</html>
