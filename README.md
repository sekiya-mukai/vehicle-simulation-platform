# Vehicle Simulation & Analysis Platform

車載ECU間通信を模擬し、通信品質の評価を行うためのC++製シミュレーションプラットフォームです。

本プロジェクトは、車載ソフトウェア開発・通信評価業務で得た知見をもとに、ECU通信、ログ取得、性能測定、品質評価を再現することを目的として開発しています。

---

## Overview

```mermaid
flowchart LR

    SenderECU["Sender ECU"]
    CANBus["CAN Bus"]
    Logger["Logger"]
    Perf["Performance Monitor"]
    Loss["Packet Loss Detector"]
    ReceiverECU["Receiver ECU"]

    SenderECU --> CANBus

    CANBus --> Logger
    CANBus --> Perf
    CANBus --> Loss
    CANBus --> ReceiverECU
```