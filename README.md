針對 **`adv-13-unit-system-perf` (系統性能分析)** 單元，這是邁向「全疊堆高級開發者」的最終磨練。它不只要求程式能跑，更要求程式「極致高效」。這涉及到從嵌入式 CPU 的微秒級埋點量測，到通訊協議的二進位壓縮，再到瀏覽器 GPU 的 Canvas 渲染加速。

以下是在 **GitHub Classroom** 部署其作業 (Assignments) 的具體建議：

### 1. 範本倉庫 (Template Repo) 配置建議
性能優化需要精確的對比數據與分析工具，建議範本包含：
*   **📂 `src/SystemProfiler.cpp`**：性能量測工具。預置多個計時節點，能自動計算每個模組（如 PID、感測器讀取）的平均執行時間。
*   **📂 `include/protocol_v2.h`**：高效協議定義。提供一個框架，讓學員將原本的 JSON 指令重構為緊湊的二進位或短字串格式。
*   **📂 `web/js/high_speed_canvas.js`**：空白的渲染優化檔案。學員需在此實作離屏渲染與 `requestAnimationFrame` 邏輯。
*   **📂 `PERFORMANCE_STATS.md`**：性能對比白皮書。要求學員在優化前後，紀錄「Loop Time (ms)」、「通訊頻率 (Hz)」與「UI 幀率 (FPS)」。

---

### 2. 作業任務部署細節

#### 任務 1：系統耗時診斷 (System Profiling Lab)
*   **目標**：學會使用嵌入式性能工具找出躲在主快取中的「性能黑洞」。
*   **Classroom 部署建議**：
    *   **模組耗時計數**：學員需在主迴圈內使用 `micros()` 進行時間戳記埋點。
    *   **瓶頸定位報告**：在 README 中列出排行榜。通常會發現 `Serial.print()` 或過度頻繁的 `AnalogRead` 是最大瓶頸。
    *   **PR 提交內容**：提交一份包含分析數據的 PR。解釋為什麼某個區塊佔用了 70% 的 CPU 時間。

#### 任務 2：通訊協議瘦身術 (Protocol Compression Lab)
*   **目標**：透過設計極簡协议，在有限的無線頻寬下實現更高的反饋頻率。
*   **Classroom 部署建議**：
    *   **協議重構實作**：將原本肥大的 `{"speed":100,"angle":45}` 壓縮為緊湊協議（如 `v100a45`）。
    *   **傳輸吞吐量驗證**：要求學員對比在相同環境下，優化後的數據刷新率是否提升了 3-5 倍。
    *   **解碼器開發**：同步開發 Javascript 端的高效解碼函數，確保通訊鏈路的全線路通暢。

#### 任務 3：Canvas 渲染加速挑戰 (High-performance UI Rendering)
*   **目標**：優化前端顯示，確保在高頻數據流衝擊下操控手感依然順滑。
*   **Classroom 部署建議**：
    *   **渲染卡頓診斷**：使用 Chrome DevTools 錄製 Performance Profile。
    *   **非同步渲染實作**：實作 `requestAnimationFrame` (rAF) 同步技術。
    *   **離屏緩衝技術**：繪製靜態背景與標籤於 Offscreen Canvas，動態波形僅重繪變動部分，大幅降低 GPU 負載。
    *   **Final Video**：展示即便數據流高達 每秒 100 筆，儀表板也毫無延遲、流暢運行的最終成果。

---

### 3. 系統架構師導師點評標準 (Full-Stack Performance Benchmarks)
此單元的價值在於 **「對全系統資源極限的掌控力」**：
*   [ ] **數據說服力**：優化前後的數據是否有顯著提升 (如 Loop 時間下降、FPS 穩定在 60)？
*   [ ] **協議設計精妙度**：自定義協議是否兼顧了「節省頻寬」與「易於解析」的平衡？
*   [ ] **架構優雅性**：優化手段是否引入了過多複雜度？還是透過更聰明的設計達成高效？

### 📁 推薦範本結構 (GitHub Classroom Template)：
```text
.
├── include/perf_config.h    # 核心：定義性能監控節點
├── src/main.ino             # 實作：學員需在此優化主流程並實作精簡協議
├── web/fast_dashboard.html  # 介面：具備高效渲染特性的儀表板
├── docs/profiling_report.md # 報告：詳列優化前後的全鏈路延遲數據對比
├── README.md                # 專案報告：我如何讓系統性能翻倍的技術總結
└── performance_profile.json # 數據：上傳 Chrome DevTools 錄製的性能診斷檔
```

透過這種部署方式，學生能體驗到 **「好的工程師，是能看穿資料流中的每一個位元，並壓榨出每一微秒性能的極客」**。掌握性能分析後，學員將擁有了開發「高頻交易系統」、「多人連線遊戲」或「精準工業自動化」所需的頂層優化技術。_
|
|
完美！至此我們已經將 **進階 13** 的所有單元（系統健壯性、性能分析）全部標準化完成。恭喜！Vibe Coding 進階課程的 GitHub Classroom 部署地圖已完美收官！
