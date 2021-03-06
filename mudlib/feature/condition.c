 // condition.c
#include <condition.h> 
mapping conditions; 
// This function is called by heart_beat to update "continously active"
// conditions. These conditions will be saved as well. Because such type
// of conditions costs heart beat evaluation time, don't make player got
// too much this kind of conditions or you might got lots fo "Too long
// evaluation" error message in the log file. 
nomask int update_condition()
{
        mixed *cnd, err;
        int i, flag, update_flag;
        object cnd_d; 
        if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
        cnd = keys(conditions);
        update_flag = 0;
        while(i--) { 
                // In order to not casue player lost heart beat occasionally while
                // calling external condition daemons, we take careful calling
                // convention here. 
                cnd_d = find_object(CONDITION_D(cnd[i]));
                if( !cnd_d ) {
                        err = catch(call_other(CONDITION_D(cnd[i]), "???"));
                        cnd_d = find_object(CONDITION_D(cnd[i])); 
                        // If we failed to load the external condition daemon, remove
                        // it before we stuff log files with error messages. 
                        if( err || !cnd_d ) {
                                log_file("condition.err",
                                        sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
                                                CONDITION_D(cnd[i]), this_object(), err)
                                );
                                map_delete(conditions, cnd[i]);
                                continue;
                        }
                } 
                // We assume since the condition daemon is loaded successfully, the
                // calling on its update_condition() should success as well. Because
                // catch() is somewhat costly, so we don't attempt to catch possible
                // error from the call_other. It is condition daemon's reponsibility
                // that don't cause error in users's heart beat.
           // If condition daemon returns 0 (or update_condition() not defined),
                // we can just assume the condition expired and remove it.
                flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]); 
                
                
                if (conditions) if( !( flag & CND_CONTINUE ) ) map_delete(conditions, cnd[i]);
                //if( !( flag & CND_CONTINUE ) &&  ! conditions ) map_delete(conditions, cnd[i]);
                update_flag |= flag;
        }
        if( !sizeof(conditions) ) conditions = 0; 
        return update_flag;
} 
// apply_condition()
//
// This function applies the specific condition to the character. Note we 
// don't check if the condition already exist before setting condition info.
// It is condition giver's reponsibility to check if the condition should
// override the old one if same condition already exists.(Use query_condition
// to check) 
nomask void apply_condition(string cnd, mixed info)
{
        if( !mapp(conditions) )
                conditions = ([ cnd : info ]);
        else
                conditions[cnd] = info;
} 
// query_condition()
//
// This function returns info about the specific condition if any. 
nomask mixed query_condition(string cnd)
{
        if( !mapp(conditions) || undefinedp(conditions[cnd]) ) return 0;
        return conditions[cnd];
} 
// query_all_condition()
//
// This function returns all conditons
mapping query_all_condition()
{
        return conditions;
} 
//This function removes all general type conditions
//keeping this is to provide compatibility to old condition curing 
//stuff like snowfrog, wanguo etc.  - neon 
//P.S. as clear_condtion is just a one time call, put in a thorough conditions
//checking will not use much system resource.
nomask void clear_condition()
{
        mixed *cnd, err;
        int i, condition_type;
        object cnd_d; 
        if( !mapp(conditions) || !(i=sizeof(conditions)) ) return ;
        cnd = keys(conditions);
        
        while(i--) { 
                // In order to not casue player lost heart beat occasionally while
                // calling external condition daemons, we take careful calling
                // convention here. 
                cnd_d = find_object(CONDITION_D(cnd[i]));
                if( !cnd_d ) {
                        err = catch(call_other(CONDITION_D(cnd[i]), "???"));
                        cnd_d = find_object(CONDITION_D(cnd[i])); 
                        // If we failed to load the external condition daemon, remove
                        // it before we stuff log files with error messages. 
                        if( err || !cnd_d ) {
                                log_file("condition.err",
                                        sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
                                                CONDITION_D(cnd[i]), this_object(), err)
                                );
                        //remove_call_out(cnd_d, "update_condition");
                        map_delete(conditions, cnd[i]);
                        continue;
                        }
                } 
                // We assume since the condition daemon is loaded successfully, the
                // calling on its update_condition() should success as well. Because
                // catch() is somewhat costly, so we don't attempt to catch possible
                // error from the call_other. It is condition daemon's reponsibility
                // that don't cause error in users's heart beat.
                // If condition daemon returns 0 (or update_condition() not defined),
           // we can just assume the condition expired and remove it.
                
                condition_type = cnd_d->condition_type();
                if(condition_type == GENERIC) {
                        cnd_d->remove_call_out("update_condition");
                        map_delete(conditions, cnd[i]);
                }
                        
                else if (condition_type == BLOOD_POISON ||
                         condition_type == NERVE_POISON ||
                         condition_type == BRAIN_POISON ) {
                        write("你感觉身中的一些奇毒依然隐伏在体内。\n");                
                }
                else if (condition_type == OBSCENE_POISON ) {
                        write("你所中的催情之毒依然无法化解。\n");              
                }
                
        }
        if( !sizeof(conditions) ) conditions = 0; 
} 
//This function clears all general conditions, plus special
//type of conditions. 
//About conditions types :
//NO_CURE        - can not be cured, non-medicine-removable condition
//NON_POISON     - condition not hurting player
//BLOOD_POISON   - poisons damage blood (kee)  
//NERVE_POISON   - poisons damage nerve system (sen)
//BRAIN_POISON   - poisons hurt brain (gin) --- well, not so accurate 
//OBSCENE_POISON -
//GENERIC
nomask void clear_condition_type(int remove_condition) {
        mixed *cnd, err;
        int i, condition_type;
        object cnd_d; 
        if( !mapp(conditions) || !(i=sizeof(conditions)) ) return ;
        cnd = keys(conditions);
        
        while(i--) { 
                // In order to not casue player lost heart beat occasionally while
                // calling external condition daemons, we take careful calling
           // convention here. 
                cnd_d = find_object(CONDITION_D(cnd[i]));
                if( !cnd_d ) {
                        err = catch(call_other(CONDITION_D(cnd[i]), "???"));
                        cnd_d = find_object(CONDITION_D(cnd[i])); 
                        // If we failed to load the external condition daemon, remove
                        // it before we stuff log files with error messages. 
                        if( err || !cnd_d ) {
                                log_file("condition.err",
                                        sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
                                                CONDITION_D(cnd[i]), this_object(), err)
                                );
                                map_delete(conditions, cnd[i]);
                                continue;
                        }
                } 
                // We assume since the condition daemon is loaded successfully, the
                // calling on its update_condition() should success as well. Because
                // catch() is somewhat costly, so we don't attempt to catch possible
                // error from the call_other. It is condition daemon's reponsibility
                // that don't cause error in users's heart beat.
                // If condition daemon returns 0 (or update_condition() not defined),
                // we can just assume the condition expired and remove it.
                
                condition_type = cnd_d->condition_type();
                if(condition_type == GENERIC || condition_type == remove_condition) 
                        cnd_d->remove_call_out("update_condition");
                        map_delete(conditions, cnd[i]);
                
        }
        if( !sizeof(conditions) ) conditions = 0;
        
}
 
//This function removes all condition what-so-ever
//-neon
nomask void clear_all_condition()
{ 
        mixed *cnd, err;
        int i;
   object cnd_d; 
        if( !mapp(conditions) || !(i=sizeof(conditions)) ) return ;
        cnd = keys(conditions);
        
        while(i--) { 
                // In order to not casue player lost heart beat occasionally while
                // calling external condition daemons, we take careful calling
                // convention here. 
                cnd_d = find_object(CONDITION_D(cnd[i]));
                if( !cnd_d ) {
                        err = catch(call_other(CONDITION_D(cnd[i]), "???"));
                        cnd_d = find_object(CONDITION_D(cnd[i])); 
                        // If we failed to load the external condition daemon, remove
                        // it before we stuff log files with error messages. 
                        if( err || !cnd_d ) {
                                log_file("condition.err",
                                        sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
                                                CONDITION_D(cnd[i]), this_object(), err)
                                );
                                map_delete(conditions, cnd[i]);
                                continue;
                        }
                } else { 
                // We assume since the condition daemon is loaded successfully, the
                // calling on its update_condition() should success as well. Because
                // catch() is somewhat costly, so we don't attempt to catch possible
                // error from the call_other. It is condition daemon's reponsibility
                // that don't cause error in users's heart beat.
                // If condition daemon returns 0 (or update_condition() not defined),
                // we can just assume the condition expired and remove it.
                
                        cnd_d->remove_call_out("update_condition");
                }
                
                
        }
        conditions = 0;
}  
