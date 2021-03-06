//
//  ModuleTree.h
//  Xspray
//
//  Created by Sébastien Métrot on 6/15/13.
//
//

#pragma once

class ModuleTree : public nuiTreeNode
{
public:
  enum Type
  {
    eTarget,
    eModule,
    eCompileUnit
  };

  ModuleTree(const lldb::SBTarget& rTarget);
  ModuleTree(const lldb::SBModule& rModule, Type type);
  ModuleTree(const lldb::SBCompileUnit& rCompileUnit);

  virtual ~ModuleTree();

  virtual void Open(bool Opened);
  bool IsEmpty() const;

  void Update();
  void UpdateTarget();
  void UpdateModule();
  void UpdateCompileUnit();

  Type GetType() const;

  nglPath GetSourcePath() const;

  const lldb::SBTarget& GetTarget() const;
  const lldb::SBModule& GetModule() const;
private:
  lldb::SBTarget mTarget;
  mutable lldb::SBModule mModule;
  lldb::SBCompileUnit mCompileUnit;
  Type mType;
};


