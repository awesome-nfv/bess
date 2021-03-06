#ifndef BESS_MODULES_FLOWGEN_H_
#define BESS_MODULES_FLOWGEN_H_

#include "../module.h"
#include "../module_msg.pb.h"

class Source final : public Module {
 public:
  static const gate_idx_t kNumIGates = 0;

  static const Commands cmds;

  Source() : Module(), pkt_size_(), burst_() {
    is_task_ = true;
  }

  CommandResponse Init(const bess::pb::SourceArg &arg);

  struct task_result RunTask(void *arg) override;

  CommandResponse CommandSetBurst(
      const bess::pb::SourceCommandSetBurstArg &arg);
  CommandResponse CommandSetPktSize(
      const bess::pb::SourceCommandSetPktSizeArg &arg);

 private:
  int pkt_size_;
  int burst_;
};

#endif  // BESS_MODULES_FLOWGEN_H_
